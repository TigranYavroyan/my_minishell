/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 18:00:05 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_C_H
#define SET_C_H

#include <list.h>
#include <libft.h>

typedef t_node_ptr			t_key_type;
typedef struct s_set_node	t_setnode;
typedef	t_setnode			*t_setnode_ptr;
typedef struct s_set		t_set;
typedef t_set				*t_set_ptr;

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

t_setnode_ptr	make_set_node (t_key_type key);
t_set_ptr		init_set ();
void			insert_set(t_set_ptr set, t_key_type key);
void			clear_set(t_set_ptr *set);


#endif // SET_C_H