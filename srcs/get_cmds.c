/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:51:38 by tigran            #+#    #+#             */
/*   Updated: 2024/09/16 20:36:19 by tigran           ###   ########.fr       */
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
			curr = curr->next->next;
			minishell->commands->cmds[i]->name = ft_strdup(curr->val);
			++i;
		}
		curr = curr->next;
	}
}


// static void	get_cmds_args(t_minishell_ptr minishell)
// {
// 	t_node_ptr	curr;
// 	int			i;

// 	curr = minishell->line->head;
// 	i = 0;
// 	while (curr)
// 	{
// 		if (curr && _equal(curr->val, "|"))
// 			++i;
// 		curr = curr->next;
// 	}
// }

static void get_cmds_options(t_minishell_ptr minishell)
{
	t_node_ptr	curr;
	int			i;

	curr = minishell->line->head;
	i = 0;
	while (curr) // can find arguments after detecting options (can use bool for understanding is there at least one option or not)
	{
		while (curr && *curr->val == '-')
		{
			push_back_lt(minishell->commands->cmds[i]->options, curr->val);
			curr = curr->next;
			while (curr && ft_isspace(*curr->val))
				curr = curr->next;
		}
		if (curr && *curr->val == '|')
			++i;
		if (curr)
			curr = curr->next;
	}
	print_lt(minishell->commands->cmds[i]->options);
}

void get_cmds(t_minishell_ptr minishell)
{
	if (!minishell->line->head)
		return ;
	init_cmd(minishell->commands);
	get_cmds_names(minishell);
	get_cmds_options(minishell);
}