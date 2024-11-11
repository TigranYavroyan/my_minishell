/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:39:56 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 00:27:01 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_set_ptr	init_set(void)
{
	t_set_ptr	set;

	set = (t_set_ptr)wrapper_malloc(sizeof(t_set));
	set->root = NULL;
	return (set);
}
