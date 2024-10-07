/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 18:05:18 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static void _clear_set(t_setnode_ptr root)
{
	if (!root)
		return ;
	_clear_set(root->left);
	_clear_set(root->right);
	free(root);
}

void	clear_set(t_set_ptr *set)
{
	if (!set || !(*set))
		return ;
	_clear_set((*set)->root);
	free(*set);
	*set = NULL;
}