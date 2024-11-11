/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:54 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 00:26:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_setnode_ptr	_find_set(t_setnode_ptr root, t_node_ptr key)
{
	if (!root)
		return (NULL);
	if (root->key == key)
		return (root);
	else if (root->key > key)
		return (_find_set(root->left, key));
	else
		return (_find_set(root->right, key));
}

bool	find_set(t_set_ptr set, t_node_ptr key)
{
	t_setnode_ptr	to_find;

	to_find = _find_set(set->root, key);
	if (!to_find)
		return (false);
	return (true);
}

t_setnode_ptr	_find_min_set(t_setnode_ptr root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}
