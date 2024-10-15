/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:39:56 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/14 20:10:11 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_set_ptr	init_set ()
{
	t_set_ptr	set;

	set = (t_set_ptr) wrapper_malloc(sizeof(t_set));
	set->root = NULL;
	return set;
}