/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/16 16:08:06 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static void				_clear(t_setnode_ptr root);
static t_setnode_ptr	_remove(t_setnode_ptr root, const t_node_ptr key);

void	clear_set(t_set_ptr set)
{
	if (!set)
		return ;
	_clear(set->root);
	set->root = NULL;
}

void	remove_set(t_set_ptr set, const t_node_ptr key)
{
	set->root = _remove(set->root, key);
}

static void	_clear(t_setnode_ptr root)
{
	if (!root)
		return ;
	_clear(root->left);
	_clear(root->right);
	_free_node_set(&root);
}

static t_setnode_ptr	_balance_remove_set(t_setnode_ptr *root)
{
	int	bf;

	bf = get_bf_set(*root);
	if (bf < -1 && get_bf_set((*root)->right) <= 0)
		return (_left_rotate_set(*root));
	if (bf > 1 && get_bf_set((*root)->left) < 0)
	{
		(*root)->left = _left_rotate_set((*root)->left);
		return (_right_rotate_set(*root));
	}
	if (bf < -1 && get_bf_set((*root)->right) <= 0)
		return (_left_rotate_set(*root));
	if (bf < -1 && get_bf_set((*root)->right) > 0)
	{
		(*root)->right = _right_rotate_set((*root)->right);
		return (_left_rotate_set(*root));
	}
	return (*root);
}

static t_setnode_ptr	_remove(t_setnode_ptr root, const t_node_ptr key)
{
	t_setnode_ptr	tmp;

	if (!root)
		return (NULL);
	if (root->key < key)
		root->right = _remove(root->right, key);
	else if (root->key > key)
		root->left = _remove(root->left, key);
	else
	{
		if (!root->left)
			tmp = root->right;
		else if (!root->right)
			tmp = root->left;
		else
		{
			tmp = _find_min_set(root->right);
			root->key = tmp->key;
			root->right = _remove(root->right, tmp->key);
			return (root);
		}
		_free_node_set(&root);
		return (tmp);
	}
	return (_balance_remove_set(&root));
}
