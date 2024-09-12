/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:39 by tigran            #+#    #+#             */
/*   Updated: 2024/09/12 18:41:39 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

value_type  get_bst (t_BST_ptr bst, const key_type key) {
    t_TreeNode_ptr to_find = _find_bst(bst->root, key);
    if (to_find == NULL)
        return NULL;
    return to_find->value;
}