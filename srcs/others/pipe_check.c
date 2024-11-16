/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:03:40 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 16:32:16 by tigran           ###   ########.fr       */
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
			if (!curr || (!ft_isalpha(*curr->val) && !find_set(quote_tracker, curr) && !is_redirect(curr->val)))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
