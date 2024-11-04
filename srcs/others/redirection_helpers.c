/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:00:55 by tigran            #+#    #+#             */
/*   Updated: 2024/11/04 21:20:54 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	__redir_swap(t_minishell_ptr minishell, t_node_ptr curr)
{
	if (curr->next->next)
	{
		push_front_lt(minishell->line, curr->next->next->val);
		remove_node_lt(minishell->line, curr->next->next);
	}
	else
		push_front_lt(minishell->line, "");
}

t_node_ptr	__redirect_handle(t_minishell_ptr minishell, t_node_ptr curr, int i)
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
	else if (_equal(curr->val, ">>"))
	{
		fd = open(curr->next->val, O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
		minishell->commands->cmds[i]->redirection = redirect_out;
		minishell->commands->cmds[i]->descriptors->stdout = fd;
	}
	else
	{
		// open file for henrik
		// fd = open(...)
		minishell->commands->cmds[i]->redirection = redirect_heredoc;
		minishell->commands->cmds[i]->delim = ft_strdup(curr->next->val); // delim (100% it exist)
		// minishell->commands->cmds[i]->descriptors->stdin = fd
	}
	curr = remove_node_lt(minishell->line, curr);
	return (remove_node_lt(minishell->line, curr));
}