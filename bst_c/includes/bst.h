/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:35 by tigran            #+#    #+#             */
/*   Updated: 2024/10/14 23:00:26 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H

# include <libft.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>


typedef enum e_travers_type_bst	t_travers_type_bst;

enum						e_travers_type_bst
{
	PREORDER,
	INORDER,
	POSTORDER,
};

typedef char				*t_key_type;
typedef char				*t_value_type;
typedef size_t				t_size_type;

typedef struct s_TreeNode	t_treenode;
typedef t_treenode			*t_treenode_ptr;
typedef struct s_BST		t_bst;
typedef t_bst				*t_bst_ptr;
typedef void				(*t_visitor_bst)(t_key_type, t_value_type);

struct						s_TreeNode
{
	t_treenode_ptr			left;
	t_treenode_ptr			right;
	t_key_type				key;
	t_value_type			value;
};

struct						s_BST
{
	t_treenode_ptr			root;
	t_size_type				size;
};

// init
t_bst_ptr					init_bst(void);
t_bst_ptr					copy_bst(const t_bst_ptr bst);
t_bst_ptr					matrix_to_bst(char **matrix, char delim);
t_bst_ptr					matrix_to_bst_none_sorted(char **matrix, char delim);

// insertion
void						insert_bst(t_bst_ptr bst, const t_key_type key,
								const t_value_type value);

// height
int							get_height_bst (t_bst_ptr tree);
int							__get_height_bst (t_treenode_ptr root);

// balance_utils
t_treenode_ptr				_left_rotate (t_treenode_ptr x);
t_treenode_ptr				_right_rotate (t_treenode_ptr x);
int							get_bf (t_treenode_ptr curr);

// deletion
void						remove_bst(t_bst_ptr bst, const t_key_type key);
void						clear_bst(t_bst_ptr *bst);

// access
t_value_type				get_bst(t_bst_ptr bst, const t_key_type key);
t_value_type				get_bst_range(t_bst_ptr bst, const t_key_type begin, const t_key_type end);

// find
t_treenode_ptr				_find_min_bst(t_treenode_ptr root);
t_treenode_ptr				_find_max_bst(t_treenode_ptr root);
t_value_type				find_min_bst(t_bst_ptr bst);
t_value_type				find_max_bst(t_bst_ptr bst);
bool						find_bst(t_bst_ptr bst, const t_key_type key);

// helpers
void						_free_node(t_treenode_ptr *root);
t_treenode_ptr				_make_node(const t_key_type key,
								const t_value_type value, t_treenode_ptr left,
								t_treenode_ptr right);
t_treenode_ptr				_make_node_move(t_key_type key, t_value_type value,
								t_treenode_ptr left, t_treenode_ptr right);
t_treenode_ptr				_find_bst(t_treenode_ptr root,
								const t_key_type key);

// traverse
void						traverse_bst(t_bst_ptr tree,
								t_travers_type_bst travers_type, t_visitor_bst fptr);

// cmp
bool						_less(const char *op1, const char *op2);
bool						_greater(const char *op1, const char *op2);
bool						_equal(const char *op1, const char *op2);

// bst_to_matrix
char						**bst_to_matrix(t_bst_ptr tree);

#endif // BST_H
