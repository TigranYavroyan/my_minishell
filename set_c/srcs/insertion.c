/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:57:10 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/12 16:18:43 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static t_setnode_ptr _balance(t_setnode_ptr root, const t_key_type key)
{
	int	bf;

	bf = get_bf(root);
	if (bf > 1 && key < root->left->key)
		return (_right_rotate(root));
	else if (bf > 1 && key > root->left->key)
	{
		root->left = _left_rotate(root->left);
		return _right_rotate(root);
	}
	else if (bf < -1 && key > root->right->key)
		return _left_rotate(root);
	else if (bf < -1 && key < root->right->key)
	{
		root->right = _right_rotate(root->right);
		return _left_rotate(root);
	}
	return (root);
}

static	t_setnode_ptr	_insert_set(t_setnode_ptr root, t_key_type key)
{
	if (!root)
		return make_set_node(key);
	if (root->key < key)
		root->right = _insert_set(root->right, key);
	else if (root->key > key)
		root->left = _insert_set(root->left, key);
	return _balance(root, key);
}

void	insert_set(t_set_ptr set, t_key_type key)
{
	if (!set)
		return ;
	set->root = _insert_set(set->root, key);
}