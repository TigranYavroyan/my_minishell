/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:03:40 by tigran            #+#    #+#             */
/*   Updated: 2024/11/20 19:07:13 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	pipe_check(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr)
	{
		if (_equal(curr->val, "|") && !find_set(quote_tracker, curr))
		{
			if (curr->prev == NULL)
				return (false);
			curr = curr->next;
			if (!curr || (!is_mergeable_util(curr->val)
					&& !is_redirect(curr->val)
					&& !find_set(quote_tracker, curr)))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
