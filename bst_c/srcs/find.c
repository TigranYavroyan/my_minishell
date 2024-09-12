/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:46 by tigran            #+#    #+#             */
/*   Updated: 2024/09/12 18:41:46 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

bool find_bst (t_BST_ptr bst, const key_type key) {
    t_TreeNode_ptr to_find = _find_bst(bst->root, key);

    if (to_find == NULL)
        return false;
    return true;
}

t_TreeNode_ptr _find_min_bst (t_TreeNode_ptr root) {
    if (!root) return NULL;

    while (root->left)
        root = root->left;
    
    return root;
}

t_TreeNode_ptr _find_max_bst (t_TreeNode_ptr root) {
    if (!root) return NULL;

    while (root->right)
        root = root->right;
    
    return root;
}

value_type  find_min_bst (t_BST_ptr bst) {
    t_TreeNode_ptr curr;

    curr = _find_min_bst(bst->root);
    if (curr == NULL)
        return NULL;
    return curr->value;
}

value_type  find_max_bst (t_BST_ptr bst) {
    t_TreeNode_ptr curr;

    curr = _find_max_bst(bst->root);
    if (curr == NULL)
        return NULL;
    return curr->value;
}