/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/14 20:13:48 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_C_H
#define SET_C_H

# include "../includes/tree_utils.h"
#include <list.h>
#include <libft.h>

typedef t_node_ptr			t_key_type;
typedef struct s_set_node	t_setnode;
typedef	t_setnode			*t_setnode_ptr;
typedef struct s_set		t_set;
typedef t_set				*t_set_ptr;
typedef void				(*t_visitor_set)(t_key_type);

struct s_set_node
{
	t_key_type		key;
	t_setnode_ptr	left;
	t_setnode_ptr	right;
};


struct s_set
{
	t_setnode_ptr	root;
};

// helpers
t_setnode_ptr	make_set_node (t_key_type key);
void			_free_node(t_setnode_ptr *root);

// init
t_set_ptr		init_set ();

// insertion
void			insert_set(t_set_ptr set, t_key_type key);

// height
int				get_height_set (t_set_ptr tree);
int				__get_height_set (t_setnode_ptr root);

// balance_utils
t_setnode_ptr	_left_rotate (t_setnode_ptr x);
t_setnode_ptr	_right_rotate (t_setnode_ptr x);
int				get_bf (t_setnode_ptr curr);

// find
t_setnode_ptr	_find_min_set(t_setnode_ptr root);
bool			find_set (t_set_ptr set, t_key_type key);

// traverse
void	traverse_set(t_set_ptr tree, t_travers_type travers_type,
		t_visitor_set fptr);

// deletion
void	clear_set(t_set_ptr *set);
void	remove_set(t_set_ptr set, const t_key_type key);



#endif // SET_C_H