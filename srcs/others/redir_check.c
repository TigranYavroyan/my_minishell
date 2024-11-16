/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:58:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 16:31:26 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_redirect(const char *val)
{
	return (_equal(val, ">") || _equal(val, "<") || _equal(val, ">>")
		|| _equal(val, "<<"));
}

void	__redir_swap(t_minishell_ptr minishell, t_node_ptr curr)
{
	if (find_set(minishell->quote_tracker, curr))
		return ;
	if (curr->next->next)
	{
		if (minishell->line->head == curr)
			push_front_lt(minishell->line, curr->next->next->val);
		else
			insert_node_lt(minishell->line, curr->next->next->val, curr->prev);
		remove_node_lt(minishell->line, curr->next->next);
	}
	else
	{
		if (minishell->line->head == curr)
			push_front_lt(minishell->line, curr->next->next->val);
		else
			insert_node_lt(minishell->line, "", curr->prev);
	}
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
