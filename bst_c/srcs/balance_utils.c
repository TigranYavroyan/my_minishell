/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:27:23 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 16:08:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

t_treenode_ptr	_left_rotate(t_treenode_ptr x)
{
	t_treenode_ptr	y;
	t_treenode_ptr	t2;

	y = x->right;
	t2 = y->left;
	y->left = x;
	x->right = t2;
	return (y);
}

t_treenode_ptr	_right_rotate(t_treenode_ptr x)
{
	t_treenode_ptr	y;
	t_treenode_ptr	t2;

	y = x->left;
	t2 = y->right;
	y->right = x;
	x->left = t2;
	return (y);
}

int	get_bf(t_treenode_ptr curr)
{
	return (__get_height_bst(curr->left) - __get_height_bst(curr->right));
}

t_treenode_ptr	_balance_remove(t_treenode_ptr *root)
{
	int	bf;

	bf = get_bf(*root);
	if (bf < -1 && get_bf((*root)->right) <= 0)
		return (_left_rotate(*root));
	if (bf > 1 && get_bf((*root)->left) < 0)
	{
		(*root)->left = _left_rotate((*root)->left);
		return (_right_rotate(*root));
	}
	if (bf < -1 && get_bf((*root)->right) <= 0)
		return (_left_rotate(*root));
	if (bf < -1 && get_bf((*root)->right) > 0)
	{
		(*root)->right = _right_rotate((*root)->right);
		return (_left_rotate(*root));
	}
	return (*root);
}
