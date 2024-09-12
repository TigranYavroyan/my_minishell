/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_bst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:04 by tigran            #+#    #+#             */
/*   Updated: 2024/09/12 18:42:04 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static t_TreeNode_ptr _init_root (char* line, char delim);
static t_TreeNode_ptr _matrix_to_bst (char** matrix, char delim, int s, int e);

t_BST_ptr matrix_to_bst (char** matrix, char delim) {
    t_BST_ptr tree = init_bst();
    int size = 0;

    while (matrix[size])
        ++size;

    tree->root = _matrix_to_bst (matrix, delim, 0, size - 1);

    return tree;
}

static t_TreeNode_ptr _init_root (char* line, char delim) {
    t_TreeNode_ptr root;
    key_type    key;
    value_type  value;

    key = ft_strchr(line, delim);
    value = ft_strchr(line, delim);
    if (!value)
        return _make_node(line, "", NULL, NULL);
    key = ft_substr(line, 0, ft_strlen(line) - ft_strlen(key));
    root = _make_node(key, value + 1, NULL, NULL);
    free(key);
    return root;
}

static t_TreeNode_ptr _matrix_to_bst (char** matrix, char delim, int s, int e) {
    t_TreeNode_ptr root;
    int mid;

    if (s > e)
        return NULL;
    
    mid = s + (e - s) / 2;
    root = _init_root(matrix[mid], delim);
    root->left = _matrix_to_bst(matrix, delim, s, mid - 1);
    root->right = _matrix_to_bst(matrix, delim, mid + 1, e);
    return root;
}
