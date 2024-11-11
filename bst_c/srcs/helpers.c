/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:51 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 00:20:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

t_treenode_ptr	_find_bst(t_treenode_ptr root, const t_key_type key)
{
	if (!root)
		return (NULL);
	if (_equal(root->key, key))
		return (root);
	else if (_less(root->key, key))
		return (_find_bst(root->right, key));
	else
		return (_find_bst(root->left, key));
}

t_treenode_ptr	_make_node(const t_key_type key, const t_value_type value,
		t_treenode_ptr left, t_treenode_ptr right)
{
	t_treenode_ptr	node;

	node = (t_treenode_ptr)wrapper_malloc(sizeof(t_treenode));
	node->key = ft_strdup(key);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = NULL;
	node->left = left;
	node->right = right;
	return (node);
}

t_treenode_ptr	_make_node_move(t_key_type key, t_value_type value,
		t_treenode_ptr left, t_treenode_ptr right)
{
	t_treenode_ptr	node;

	node = (t_treenode_ptr)wrapper_malloc(sizeof(t_treenode));
	node->key = key;
	node->value = value;
	node->left = left;
	node->right = right;
	return (node);
}

void	_free_node(t_treenode_ptr *root)
{
	free((*root)->key);
	free((*root)->value);
	free(*root);
	*root = NULL;
}
