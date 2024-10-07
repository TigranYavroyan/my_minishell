/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:39:56 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 17:47:23 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_set_ptr	init_set ()
{
	t_set_ptr	set;

	set = (t_set_ptr) wrapper_malloc(sizeof(t_set));
	set->root = make_set_node(NULL);
	return set;
}