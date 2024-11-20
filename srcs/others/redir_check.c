/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:58:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/20 18:11:39 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_redirect(const char *val)
{
	return (_equal(val, ">") || _equal(val, "<") || _equal(val, ">>")
		|| _equal(val, "<<"));
}

static t_node_ptr	_find_last_redir(t_node_ptr curr, t_set_ptr quote_tracker)
{
	t_node_ptr	last_redir;

	last_redir = curr;
	while (curr)
	{
		if (is_redirect(curr->val) && !find_set(quote_tracker, curr))
			last_redir = curr;
		curr = curr->next;
	}
	return (last_redir);
}

void	__redir_swap(t_minishell_ptr minishell, t_node_ptr curr)
{
	t_node_ptr	tmp;

	if (find_set(minishell->quote_tracker, curr))
		return ;
	tmp = _find_last_redir(curr, minishell->quote_tracker);
	tmp = tmp->next->next;
	if (tmp && (is_mergeable_util(tmp->val)
			|| find_set(minishell->quote_tracker, tmp)))
	{
		if (minishell->line->head == curr)
			push_front_lt(minishell->line, tmp->val);
		else
			insert_node_lt(minishell->line, tmp->val, curr->prev);
		remove_node_lt(minishell->line, tmp);
	}
	else
	{
		if (minishell->line->head == curr)
			push_front_lt(minishell->line, "");
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
