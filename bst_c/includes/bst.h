/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:35 by tigran            #+#    #+#             */
/*   Updated: 2024/09/12 18:41:36 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
#define BST_H

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef enum e_travers_type t_travers_type;
typedef char*               key_type;
typedef char*               value_type;
typedef size_t              size_type;

typedef struct s_TreeNode   t_TreeNode;
typedef t_TreeNode*         t_TreeNode_ptr;
typedef struct s_BST        t_BST;
typedef t_BST*              t_BST_ptr;
typedef void (*visitor)(key_type, value_type);

enum e_travers_type {
    PREORDER,
    INORDER,
    POSTORDER,
};

struct s_TreeNode {
    t_TreeNode_ptr left;
    t_TreeNode_ptr right;
    key_type key;
    value_type value;
};

struct s_BST {
    t_TreeNode_ptr root;
    size_type      size;
};

// init
t_BST_ptr   init_bst ();
t_BST_ptr   copy_bst (const t_BST_ptr bst);
t_BST_ptr   matrix_to_bst (char** matrix, char delim);

// insertion
void        insert_bst (t_BST_ptr bst, const key_type key, const value_type value);
void        update_bst (t_BST_ptr bst, const key_type key, const value_type value);

// deletion
void        remove_bst (t_BST_ptr bst, const key_type key);
void        clear_bst (t_BST_ptr* bst);

// access
value_type  get_bst (t_BST_ptr bst, const key_type key);

// find
t_TreeNode_ptr _find_min_bst (t_TreeNode_ptr root);
t_TreeNode_ptr _find_max_bst (t_TreeNode_ptr root);
value_type  find_min_bst (t_BST_ptr bst);
value_type  find_max_bst (t_BST_ptr bst);
bool        find_bst (t_BST_ptr bst, const key_type key);

// helpers
void            _free_node (t_TreeNode_ptr* root);
t_TreeNode_ptr   _make_node (const key_type key, const value_type value, t_TreeNode_ptr left, t_TreeNode_ptr right) __attribute__((warn_unused_result, malloc));
t_TreeNode_ptr   _make_node_move (key_type key, value_type value, t_TreeNode_ptr left, t_TreeNode_ptr right);
t_TreeNode_ptr  _find_bst(t_TreeNode_ptr root, const key_type key);

// traverse
void traverse_bst (t_BST_ptr tree, t_travers_type travers_type, visitor fptr);

// cmp
bool _less (const char* op1, const char* op2);
bool _greater (const char* op1, const char* op2);
bool _equal (const char* op1, const char* op2);


#endif // BST_H
