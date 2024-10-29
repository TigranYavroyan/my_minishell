/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:51:38 by tigran            #+#    #+#             */
/*   Updated: 2024/10/29 18:50:21 by tigran           ###   ########.fr       */
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

static t_node_ptr get_cmds_attr(t_minishell_ptr minishell, t_node_ptr head, int i)
{
	t_node_ptr	curr;

	if (!head || !head->next)
		return (NULL);
	curr = head->next;
	while (curr && *curr->val == '-')
	{
		push_back_lt(minishell->commands->cmds[i]->options, curr->val);
		curr = curr->next;
	}
	while (curr)
	{
		if (*curr->val == '|')
			return (curr);
		push_back_lt(minishell->commands->cmds[i]->args, curr->val);
		curr = curr->next;
	}
	return (NULL);
}

void get_cmds(t_minishell_ptr minishell)
{
	t_node_ptr	possible_pipe;
	int			i;

	if (!minishell->line->head)
		return ;
	i = 0;
	init_cmd(minishell->commands);
	get_cmds_names(minishell);
	possible_pipe = get_cmds_attr(minishell, minishell->line->head, i);
	while (possible_pipe)
	{
		++i;
		possible_pipe = get_cmds_attr(minishell, possible_pipe->next, i);
	}
	// for (int i = 0; i < minishell->commands->size; ++i)
	// {
	// 	printf("The name: %s\n", minishell->commands->cmds[i]->name);
	// 	printf("Options: ");
	// 	print_lt(minishell->commands->cmds[i]->options);
	// 	printf("Args: ");
	// 	print_lt(minishell->commands->cmds[i]->args);
	// 	printf("\n\n");
	// }
	// exit(0);
}