/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:01:23 by tigran            #+#    #+#             */
/*   Updated: 2024/10/03 19:44:01 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	_update_quote_info(bool *open, char *opened_ch, t_node_ptr curr);
static void	_remove_head_spaces(t_list_ptr line);
static void	_remove_spaces(t_list_ptr line, t_node_ptr *curr);

void	ft_symbol_resolution(t_minishell_ptr minishell)
{
	bool		open;
	char		opened_ch;
	t_node_ptr	curr;

	open = false;
	opened_ch = 0;
	_remove_head_spaces(minishell->line);
	curr = minishell->line->head;
	while (curr)
	{
		if (!open && ft_isspace(*curr->val))
			_remove_spaces(minishell->line, &curr);
		if (curr && *curr->val == '$') // e$boba hello
			ft_dollar_resolution(minishell, curr, curr->val + 1, opened_ch);
		if (curr)
		{
			_update_quote_info(&open, &opened_ch, curr);
			curr = curr->next;
		}
	}
}

static void	_update_quote_info(bool *open, char *opened_ch, t_node_ptr curr)
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

static void	_remove_head_spaces(t_list_ptr line)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr && ft_isspace(*curr->val))
	{
		pop_front_lt(line);
		curr = line->head;
	}
}

static void	_remove_spaces(t_list_ptr line, t_node_ptr *curr)
{
	t_node_ptr	tmp;

	tmp = *curr;
	while (*curr && ft_isspace(*(*curr)->val))
	{
		tmp = (*curr)->next;
		remove_node_lt(line, *curr);
		*curr = tmp;
	}
}
