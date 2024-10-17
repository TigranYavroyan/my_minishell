/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:08:58 by tigran            #+#    #+#             */
/*   Updated: 2024/10/17 19:17:55 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

bool	is_single_quoted(t_set_ptr set, t_node_ptr key)
{
	t_setnode_ptr	to_find;

	if (!key)
		return (false);

	to_find = _find_set(set->root, key);
	if (to_find)
		return (to_find->q_type == SINGLE_QUOTE);
	return (false);
}

bool	is_double_quoted(t_set_ptr set, t_node_ptr key)
{
	t_setnode_ptr	to_find;

	if (!key)
		return (false);

	to_find = _find_set(set->root, key);
	if (to_find)
		return (to_find->q_type == DOUBLE_QUOTE);
	return (false);
}