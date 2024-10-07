/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:54 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 18:10:47 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static t_setnode_ptr _find_set(t_setnode_ptr root, t_key_type key)
{
	if (!root)
		return (NULL);
	if (root->key == key)
		return (root);
	else if (root->key > key)
		return _find_set(root->left, key);
	else
		return _find_set(root->right, key);
}

bool	find_set (t_set_ptr set, t_key_type key)
{
	t_setnode_ptr	to_find;
	to_find = _find_set(set->root, key);
	if (!to_find)
		return (false);
	return (true);
}