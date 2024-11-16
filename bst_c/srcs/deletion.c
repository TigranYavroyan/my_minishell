/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:43 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 15:32:06 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static void				_clear(t_treenode_ptr root);
static void				_copy_bst(t_treenode_ptr to, t_treenode_ptr from);
static t_treenode_ptr	_remove(t_treenode_ptr root, const t_key_type key);

void	clear_bst(t_bst_ptr *bst)
{
	if (!bst || !(*bst))
		return ;
	_clear((*bst)->root);
	free(*bst);
	*bst = NULL;
}

void	remove_bst(t_bst_ptr bst, const t_key_type key)
{
	if (_find_bst(bst->root, key))
		--bst->size;
	bst->root = _remove(bst->root, key);
}

static void	_clear(t_treenode_ptr root)
{
	if (!root)
		return ;
	_clear(root->left);
	_clear(root->right);
	_free_node(&root);
}

static void	_copy_bst(t_treenode_ptr to, t_treenode_ptr from)
{
	free(to->key);
	free(to->value);
	to->key = ft_strdup(from->key);
	if (from->value)
		to->value = ft_strdup(from->value);
	else
		to->value = NULL;
}

static t_treenode_ptr	_remove(t_treenode_ptr root, const t_key_type key)
{
	t_treenode_ptr	tmp;

	if (!root)
		return (NULL);
	if (_less(root->key, key))
		root->right = _remove(root->right, key);
	else if (_greater(root->key, key))
		root->left = _remove(root->left, key);
	else
	{
		if (!root->left)
			tmp = root->right;
		else if (!root->right)
			tmp = root->left;
		else
		{
			tmp = _find_min_bst(root->right);
			_copy_bst(root, tmp);
			root->right = _remove(root->right, tmp->key);
			return (root);
		}
		_free_node(&root);
		return (tmp);
	}
	return _balance_remove(&root);
}