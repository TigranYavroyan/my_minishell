/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:40:23 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 18:05:35 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_setnode_ptr make_set_node (t_key_type key)
{
	t_setnode_ptr	node;

	node = (t_setnode_ptr)wrapper_malloc(sizeof(t_setnode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}