/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:27:23 by tigran            #+#    #+#             */
/*   Updated: 2024/10/09 17:26:12 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

t_treenode_ptr	_left_rotate (t_treenode_ptr x)
{
	t_treenode_ptr	y;
	t_treenode_ptr	t2;

	y = x->right;
	t2 = y->left;
	y->left = x;
	x->right = t2;
	return (y);
}

t_treenode_ptr	_right_rotate (t_treenode_ptr x)
{
	t_treenode_ptr	y;
	t_treenode_ptr	t2;

	y = x->left;
	t2 = y->right;
	y->right = x;
	x->left = t2;
	return (y);
}

int	get_bf (t_treenode_ptr curr)
{
	return __get_height_bst(curr->left) - __get_height_bst(curr->right);
}
