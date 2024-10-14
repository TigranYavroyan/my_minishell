/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/14 20:22:51 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static void				_clear(t_setnode_ptr root);
static t_setnode_ptr	_remove(t_setnode_ptr root, const t_key_type key);

void	clear_set(t_set_ptr *set)
{
	if (!set || !(*set))
		return ;
	_clear((*set)->root);
	free(*set);
	*set = NULL;
}

void	remove_set(t_set_ptr set, const t_key_type key)
{
	set->root = _remove(set->root, key);
}

static void	_clear(t_setnode_ptr root)
{
	if (!root)
		return ;
	_clear(root->left);
	_clear(root->right);
	_free_node(&root);
}

static t_setnode_ptr	_remove(t_setnode_ptr root, const t_key_type key)
{
	t_setnode_ptr	tmp;
	int				bf;

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
		_free_node(&root);
		return (tmp);
	}
	bf = get_bf(root);
	if (bf < -1 && get_bf(root->right) <= 0)
		return _left_rotate(root);
	if (bf > 1 && get_bf(root->left) < 0)
    {
        root->left = _left_rotate(root->left);
        return _right_rotate(root);
    }
    if (bf < -1 && get_bf(root->right) <= 0)
        return _left_rotate(root);
    if (bf < -1 && get_bf(root->right) > 0)
    {
        root->right = _right_rotate(root->right);
        return _left_rotate(root);
    }
	return (root);
}
