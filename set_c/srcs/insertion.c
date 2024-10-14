/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:57:10 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/14 23:02:32 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static t_setnode_ptr _balance_set(t_setnode_ptr root, const t_node_ptr key)
{
	int	bf;

	bf = get_bf_set(root);
	if (bf > 1 && key < root->left->key)
		return (_right_rotate_set(root));
	else if (bf > 1 && key > root->left->key)
	{
		root->left = _left_rotate_set(root->left);
		return _right_rotate_set(root);
	}
	else if (bf < -1 && key > root->right->key)
		return _left_rotate_set(root);
	else if (bf < -1 && key < root->right->key)
	{
		root->right = _right_rotate_set(root->right);
		return _left_rotate_set(root);
	}
	return (root);
}

static	t_setnode_ptr	_insert_set(t_setnode_ptr root, t_node_ptr key, t_quote_type q_type)
{
	if (!root)
		return make_set_node(key, q_type);
	if (root->key < key)
		root->right = _insert_set(root->right, key, q_type);
	else if (root->key > key)
		root->left = _insert_set(root->left, key, q_type);
	return _balance_set(root, key);
}

void	insert_set(t_set_ptr set, t_node_ptr key, t_quote_type q_type)
{
	if (!set)
		return ;
	set->root = _insert_set(set->root, key, q_type);
}