/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:01:23 by tigran            #+#    #+#             */
/*   Updated: 2024/10/17 22:08:30 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_quotes(t_list_ptr line, t_set_ptr quote_tracker) {
	bool			open;
	char			opened_ch;
	t_node_ptr		curr;

	open = false;
	opened_ch = 0;
	curr = line->head;
	while (curr)
	{
		if (!open)
		{
			if (curr->next && _equal(curr->val, "$") && is_quote(*curr->next->val)) // handling for $'adf' case
				curr = remove_node_lt(line, curr);
		}
		update_quote_info(&open, &opened_ch, curr);
		if (is_quote(*curr->val))
			curr = remove_node_lt(line, curr);
		else
		{
			if (open)
				insert_set(quote_tracker, curr, get_quote_type(opened_ch));
			curr = curr->next;
		}
	}
}

void	parse_dollar (t_minishell_ptr minishell)
{
	t_node_ptr		curr;
	t_value_type	begin;

	curr = minishell->line->head;
	while (curr)
	{
		begin = ft_strchr(curr->val, '$');
		if (begin) {
			ft_dollar_resolution(minishell, curr, begin + 1);
			if (curr->val && !(*curr->val))
				curr = remove_node_lt(minishell->line, curr);
			else
				curr = curr->next; // kolxoz, but works
		}
		else
			curr = curr->next;
	}
}

void	remove_spaces(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr)
	{
		if (ft_isspace(*curr->val) && !find_set(quote_tracker, curr))
			curr = remove_node_lt(line, curr);
		else
			curr = curr->next;
	}
}

void	update_quote_info(bool *open, char *opened_ch, t_node_ptr curr)
{
	if (is_quote(*curr->val))
	{
		if (!(*open))
		{
			*open = true;
			*opened_ch = *curr->val;
		}
		else if (*opened_ch == *curr->val)
		{
			*open = false;
			*opened_ch = 0;
		}
	}
}

void merge_in_quotes(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr && curr->next) // maybe can be better
	{
		if (ft_isspace(*curr->val) && !find_set(quote_tracker, curr))
			curr = curr->next;
		else if (curr && curr->next && (find_set(quote_tracker, curr->next) || !ft_isspace(*curr->next->val))) {
			ft_append(&curr->val, curr->next->val);
			remove_node_lt(line, curr->next);
		}
		else
			curr = curr->next;
	}
}