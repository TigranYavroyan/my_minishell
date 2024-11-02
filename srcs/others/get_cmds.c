/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:51:38 by tigran            #+#    #+#             */
/*   Updated: 2024/11/02 20:13:47 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void __redir_swap(t_minishell_ptr minishell, t_node_ptr curr)
{
	if (curr->next->next)
	{
		push_front_lt(minishell->line, curr->next->next->val);
		remove_node_lt(minishell->line, curr->next->next);
	}
	else
		push_front_lt(minishell->line, "");
}

static void	get_cmds_names(t_minishell_ptr minishell)
{
	t_node_ptr	curr;
	int			i;

	if (is_redirect(minishell->line->head->val))
		__redir_swap(minishell, minishell->line->head);
	curr = minishell->line->head;
	minishell->commands->cmds[0]->name = ft_strdup(curr->val);
	i = 1;
	while (curr)
	{
		if (_equal(curr->val, "|"))
		{
			curr = curr->next;
			if (is_redirect(curr->val))
				__redir_swap(minishell, curr);
			minishell->commands->cmds[i]->name = ft_strdup(curr->val);
			++i;
		}
		curr = curr->next;
	}
}

static t_node_ptr __redirect_handle(t_minishell_ptr minishell, t_node_ptr curr, int i)
{
	int	fd;
	
	if (_equal(curr->val, ">"))
	{
		fd = open(curr->next->val, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
		minishell->commands->cmds[i]->redirection = redirect_out;
		minishell->commands->cmds[i]->descriptors->stdout = fd;
	}
	else if (_equal(curr->val, "<"))
	{
		fd = open(curr->next->val, O_RDONLY | O_CREAT, FILE_PERM);
		minishell->commands->cmds[i]->redirection = redirect_in;
		minishell->commands->cmds[i]->descriptors->stdin = fd;
	}
	else
	{
		fd = open(curr->next->val, O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
		minishell->commands->cmds[i]->redirection = redirect_out;
		minishell->commands->cmds[i]->descriptors->stdout = fd;
	}
	curr = remove_node_lt(minishell->line, curr);
	return (remove_node_lt(minishell->line, curr));
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
		if (_equal(curr->val, "|"))
			return (curr);
		if (is_redirect(curr->val) && !find_set(minishell->quote_tracker, curr))
			curr = __redirect_handle(minishell, curr, i);
		else
		{
			push_back_lt(minishell->commands->cmds[i]->args, curr->val);
			curr = curr->next;
		}
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