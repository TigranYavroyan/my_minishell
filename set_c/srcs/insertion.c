/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:57:10 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 18:05:55 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static	t_setnode_ptr	_insert_set(t_setnode_ptr root, t_key_type key)
{
	if (!root)
		return make_set_node(key);
	if (root->key < key)
		root->right = _insert_set(root->right, key);
	else if (root->key > key)
		root->left = _insert_set(root->left, key);
	return (root);
}

void	insert_set(t_set_ptr set, t_key_type key)
{
	if (!set)
		return ;
	set->root = _insert_set(set->root, key);
}