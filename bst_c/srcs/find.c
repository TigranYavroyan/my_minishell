/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:46 by tigran            #+#    #+#             */
/*   Updated: 2024/09/29 15:32:32 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

bool	find_bst(t_bst_ptr bst, const t_key_type key)
{
	t_treenode_ptr	to_find;

	to_find = _find_bst(bst->root, key);
	if (to_find == NULL)
		return (false);
	return (true);
}

t_treenode_ptr	_find_min_bst(t_treenode_ptr root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}

t_treenode_ptr	_find_max_bst(t_treenode_ptr root)
{
	if (!root)
		return (NULL);
	while (root->right)
		root = root->right;
	return (root);
}

t_value_type	find_min_bst(t_bst_ptr bst)
{
	t_treenode_ptr	curr;

	curr = _find_min_bst(bst->root);
	if (curr == NULL)
		return (NULL);
	return (curr->value);
}

t_value_type	find_max_bst(t_bst_ptr bst)
{
	t_treenode_ptr	curr;

	curr = _find_max_bst(bst->root);
	if (curr == NULL)
		return (NULL);
	return (curr->value);
}
