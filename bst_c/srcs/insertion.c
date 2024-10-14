/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:57 by tigran            #+#    #+#             */
/*   Updated: 2024/10/14 19:46:53 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static t_treenode_ptr	__insert(t_treenode_ptr root, const t_key_type key,
							const t_value_type value);
static void				_update_old_value(t_treenode_ptr TreeNode,
							const t_value_type value);
static t_treenode_ptr	_balance(t_treenode_ptr root, const t_key_type key);

void	insert_bst(t_bst_ptr bst, const t_key_type key,
		const t_value_type value)
{
	if (!find_bst(bst, key))
		++bst->size;
	bst->root = __insert(bst->root, key, value);
}

static t_treenode_ptr _balance(t_treenode_ptr root, const t_key_type key)
{
	int	bf;

	bf = get_bf(root);
	if (bf > 1 && key < root->left->key)
		return (_right_rotate(root));
	else if (bf > 1 && key > root->left->key)
	{
		root->left = _left_rotate(root->left);
		return _right_rotate(root);
	}
	else if (bf < -1 && key > root->right->key)
		return _left_rotate(root);
	else if (bf < -1 && key < root->right->key)
	{
		root->right = _right_rotate(root->right);
		return _left_rotate(root);
	}
	return (root);
}

static t_treenode_ptr	__insert(t_treenode_ptr root, const t_key_type key,
		const t_value_type value)
{	
	if (!root)
		return (_make_node(key, value, NULL, NULL));
	if (_less(root->key, key))
		root->right = __insert(root->right, key, value);
	else if (_greater(root->key, key))
		root->left = __insert(root->left, key, value);
	else {
		_update_old_value(root, value);
		return (root);
	}
	return _balance(root, key);
}

static void	_update_old_value(t_treenode_ptr TreeNode, const t_value_type value)
{
	free(TreeNode->value);
	TreeNode->value = ft_strdup(value);
}
