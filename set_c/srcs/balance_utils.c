/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:32:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/12 16:59:51 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_setnode_ptr	_left_rotate (t_setnode_ptr x)
{
	t_setnode_ptr	y;
	t_setnode_ptr	t2;

	y = x->right;
	t2 = y->left;
	y->left = x;
	x->right = t2;
	return (y);
}

t_setnode_ptr	_right_rotate (t_setnode_ptr x)
{
	t_setnode_ptr	y;
	t_setnode_ptr	t2;

	y = x->left;
	t2 = y->right;
	y->right = x;
	x->left = t2;
	return (y);
}

int	get_bf (t_setnode_ptr curr)
{
	return __get_height_set(curr->left) - __get_height_set(curr->right);
}