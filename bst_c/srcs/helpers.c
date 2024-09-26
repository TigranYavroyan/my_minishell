/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:51 by tigran            #+#    #+#             */
/*   Updated: 2024/09/26 14:39:42 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

t_TreeNode_ptr _find_bst(t_TreeNode_ptr root, const key_type key) {
    if (!root)
        return (NULL);
    if (_equal(root->key, key))
        return root;
    else if (_less(root->key, key))
        return _find_bst(root->right, key);
    else
        return _find_bst(root->left, key);
}

t_TreeNode_ptr _make_node (const key_type key, const value_type value, t_TreeNode_ptr left, t_TreeNode_ptr right) {
    t_TreeNode_ptr node = (t_TreeNode_ptr) wrapper_malloc (sizeof(t_TreeNode));
    node->key = ft_strdup(key);
    if (value)
        node->value = ft_strdup(value);
    else
        node->value = NULL;
    node->left = left;
    node->right = right;
    return node;
}

t_TreeNode_ptr _make_node_move (key_type key, value_type value, t_TreeNode_ptr left, t_TreeNode_ptr right) {
    t_TreeNode_ptr node = (t_TreeNode_ptr) wrapper_malloc (sizeof(t_TreeNode));
    node->key = key;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

void _free_node (t_TreeNode_ptr* root) {
    free((*root)->key);
    free((*root)->value);
    free(*root);
    *root = NULL;
}

