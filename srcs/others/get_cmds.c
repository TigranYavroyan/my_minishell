/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:51:38 by tigran            #+#    #+#             */
/*   Updated: 2024/11/15 22:20:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_cmds_names(t_minishell_ptr minishell)
{
	t_node_ptr	curr;
	t_node_ptr	tmp;
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
			tmp = curr;
			curr = curr->next;
			if (is_redirect(curr->val))
			{
				__redir_swap(minishell, curr);
				curr = tmp->next;
			}
			minishell->commands->cmds[i]->name = ft_strdup(curr->val);
			++i;
		}
		curr = curr->next;
	}
}

static t_node_ptr	__till_pipe(t_node_ptr curr)
{
	while (curr)
	{
		if (_equal(curr->val, "|"))
			return (curr);
		curr = curr->next;
	}
	return (curr);
}

t_node_ptr	execlop(t_node_ptr	curr, t_minishell_ptr minishell, int i)
{
	while (curr)
	{
		if (_equal(curr->val, "|"))
			return (curr);
		if (is_redirect(curr->val) && !find_set(minishell->quote_tracker, curr))
		{
			curr = __redirect_handle(minishell, curr, i);
			if (minishell->commands->cmds[i]->redirection == invalid_permission)
				return (__till_pipe(curr));
		}
		else
		{
			push_back_lt(minishell->commands->cmds[i]->args, curr->val);
			curr = curr->next;
		}
	}
	return (NULL);
}

static t_node_ptr	get_cmds_attr(t_minishell_ptr minishell, t_node_ptr head,
		int i)
{
	t_node_ptr	curr;

	curr = NULL;
	if (!head || !head->next)
		return (NULL);
	curr = head->next;
	while (curr && *curr->val == '-')
	{
		push_back_lt(minishell->commands->cmds[i]->options, curr->val);
		curr = curr->next;
	}
	return (execlop(curr, minishell, i));
}

void	get_cmds(t_minishell_ptr minishell)
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
}
