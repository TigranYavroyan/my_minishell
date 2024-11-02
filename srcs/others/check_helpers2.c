/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:58:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/02 17:54:29 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_redirect (const char* val)
{
	if (_equal(val, ">") || _equal(val, "<") || _equal(val, ">>"))
		return (true);
	return (false);
}

bool	redir_check(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr)
	{
		if (is_redirect(curr->val) && !find_set(quote_tracker, curr) && !curr->next)
			return (false);
		curr = curr->next;
	}
	return (true);
}