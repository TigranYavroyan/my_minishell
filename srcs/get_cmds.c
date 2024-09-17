/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:51:38 by tigran            #+#    #+#             */
/*   Updated: 2024/09/17 15:48:57 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_cmds_names(t_minishell_ptr minishell)
{
	t_node_ptr	curr;
	int			i;

	curr = minishell->line->head;
	minishell->commands->cmds[0]->name = ft_strdup(minishell->line->head->val);
	i = 1;
	while (curr)
	{
		if (_equal(curr->val, "|"))
		{
			curr = curr->next;
			minishell->commands->cmds[i]->name = ft_strdup(curr->val);
			++i;
		}
		curr = curr->next;
	}
}

static void get_cmds_attr(t_minishell_ptr minishell)
{
	t_node_ptr	curr;
	int			i;

	if (!minishell->line->head->next)
		return ;
	curr = minishell->line->head->next;
	i = 0;
	while (curr && *curr->val == '-')
	{
		push_back_lt(minishell->commands->cmds[i]->options, curr->val);
		curr = curr->next;
	}
	while (curr) // There no handle for pipes
	{
		push_back_lt(minishell->commands->cmds[i]->args, curr->val);
		curr = curr->next;
	}
}

void get_cmds(t_minishell_ptr minishell)
{
	if (!minishell->line->head)
		return ;
	init_cmd(minishell->commands);
	get_cmds_names(minishell); // Can change with pipes
	get_cmds_attr(minishell); // There no handle for pipes
}