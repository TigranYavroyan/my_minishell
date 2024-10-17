/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/17 19:14:37 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_C_H
#define SET_C_H

#include <list.h>
#include <libft.h>

typedef enum e_travers_type_set	t_travers_type_set;
typedef struct s_set_node	t_setnode;
typedef	t_setnode			*t_setnode_ptr;
typedef struct s_set		t_set;
typedef t_set				*t_set_ptr;
typedef void				(*t_visitor_set)(t_node_ptr);
typedef enum s_quote_type	t_quote_type;

enum						e_travers_type_set
{
	PREORDER_SET,
	INORDER_SET,
	POSTORDER_SET
};

enum	s_quote_type
{
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
};

struct s_set_node
{
	t_node_ptr		key;
	t_quote_type	q_type;
	t_setnode_ptr	left;
	t_setnode_ptr	right;
};


struct s_set
{
	t_setnode_ptr	root;
};

// helpers
t_setnode_ptr	make_set_node (t_node_ptr key, t_quote_type q_type);
void			_free_node_set(t_setnode_ptr *root);
t_quote_type	get_quote_type (char ch);

// init
t_set_ptr		init_set ();

// insertion
void			insert_set(t_set_ptr set, t_node_ptr key, t_quote_type q_type);

// height
int				get_height_set (t_set_ptr tree);
int				__get_height_set (t_setnode_ptr root);

// balance_utils
t_setnode_ptr	_left_rotate_set (t_setnode_ptr x);
t_setnode_ptr	_right_rotate_set (t_setnode_ptr x);
int				get_bf_set (t_setnode_ptr curr);

// find
t_setnode_ptr	_find_min_set(t_setnode_ptr root);
bool			find_set (t_set_ptr set, t_node_ptr key);
t_setnode_ptr	_find_set(t_setnode_ptr root, t_node_ptr key);

// traverse
void	traverse_set(t_set_ptr tree, t_travers_type_set travers_type,
		t_visitor_set fptr);

// deletion
void	clear_set(t_set_ptr set);
void	remove_set(t_set_ptr set, const t_node_ptr key);

// quote_check.c
bool	is_single_quoted(t_set_ptr set, t_node_ptr curr);
bool	is_double_quoted(t_set_ptr set, t_node_ptr curr);

#endif // SET_C_H