/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:58:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 17:52:45 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_redirect(const char *val)
{
	return (_equal(val, ">") || _equal(val, "<") || _equal(val, ">>")
		|| _equal(val, "<<"));
}

char	*redir_check(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr)
	{
		if (is_redirect(curr->val) && !find_set(quote_tracker, curr)
			&& !curr->next)
			return ("newline");
		if (is_redirect(curr->val) && curr->next && !find_set(quote_tracker,
				curr->next) && !is_mergeable_util(curr->next->val))
			return (curr->next->val);
		curr = curr->next;
	}
	return (NULL);
}
