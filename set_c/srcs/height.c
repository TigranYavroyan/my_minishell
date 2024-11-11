/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:16:01 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 00:26:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

int	get_height_set(t_set_ptr tree)
{
	if (!tree)
		return (-1);
	return (__get_height_set(tree->root));
}

int	__get_height_set(t_setnode_ptr root)
{
	int	left;
	int	right;
	int	max;

	if (!root)
		return (-1);
	left = __get_height_set(root->left);
	right = __get_height_set(root->right);
	if (left > right)
		max = left + 1;
	else
		max = right + 1;
	return (max);
}
