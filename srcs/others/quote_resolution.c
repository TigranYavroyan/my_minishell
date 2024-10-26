/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:45:54 by tigran            #+#    #+#             */
/*   Updated: 2024/10/26 22:46:21 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	update_quote_info(bool *open, char *opened_ch, t_node_ptr curr)
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

static void	parse_quotes(t_list_ptr line, t_set_ptr quote_tracker) {
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
			if (_equal(curr->val, "$") && curr->next && is_quote(*curr->next->val)) // handling for $'adf' case
				curr = remove_node_lt(line, curr);
		}
		if (open && *curr->val != opened_ch)
			insert_set(quote_tracker, curr, get_quote_type(opened_ch));
		update_quote_info(&open, &opened_ch, curr);
		curr = curr->next;
	}
}

void remove_quotes (t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	parse_quotes(line, quote_tracker);
	curr = line->head;
	while (curr) {
		if (is_quote(*curr->val) && !find_set(quote_tracker, curr))
			curr = remove_node_lt(line, curr);
		else
			curr = curr->next;
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