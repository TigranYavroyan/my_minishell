/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:57 by tigran            #+#    #+#             */
/*   Updated: 2024/09/29 15:33:09 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static t_treenode_ptr	__insert(t_treenode_ptr root, const t_key_type key,
							const t_value_type value);
static void				_update_old_value(t_treenode_ptr TreeNode,
							const t_value_type value);

void	insert_bst(t_bst_ptr bst, const t_key_type key,
		const t_value_type value)
{
	if (!find_bst(bst, key))
	{
		bst->root = __insert(bst->root, key, value);
		++bst->size;
	}
}

void	update_bst(t_bst_ptr bst, const t_key_type key,
		const t_value_type value)
{
	t_treenode_ptr	x;
	t_treenode_ptr	y;

	x = bst->root;
	while (x)
	{
		y = x;
		if (_equal(x->key, key))
			return (_update_old_value(x, value));
		if (_less(x->key, key))
			x = x->right;
		else
			x = x->left;
	}
	if (_less(y->key, key))
		y->right = _make_node(key, value, NULL, NULL);
	else
		y->left = _make_node(key, value, NULL, NULL);
	++bst->size;
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
	return (root);
}

static void	_update_old_value(t_treenode_ptr TreeNode, const t_value_type value)
{
	free(TreeNode->value);
	TreeNode->value = ft_strdup(value);
}
