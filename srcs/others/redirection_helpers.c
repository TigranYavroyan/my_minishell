/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:00:55 by tigran            #+#    #+#             */
/*   Updated: 2024/11/14 18:29:36 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	__redir_swap(t_minishell_ptr minishell, t_node_ptr curr)
{
	if (find_set(minishell->quote_tracker, curr))
		return ;
	if (curr->next->next)
	{
		push_front_lt(minishell->line, curr->next->next->val);
		remove_node_lt(minishell->line, curr->next->next);
	}
	else
		push_front_lt(minishell->line, "");
}

t_node_ptr	__redirect_handle(t_minishell_ptr minishell, t_node_ptr curr, int i, bool *perm_err)
{
	int	fd;

	if (_equal(curr->val, ">"))
	{
		fd = ft_open(curr->next->val, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
		if (fd < 0)
			*perm_err = true;
		minishell->commands->cmds[i]->redirection = redirect_out;
		close(minishell->commands->cmds[i]->descriptors->stdout);
		minishell->commands->cmds[i]->descriptors->stdout = fd;
	}
	else if (_equal(curr->val, "<"))
	{
		fd = ft_open(curr->next->val, O_RDONLY | O_CREAT, FILE_PERM);
		if (fd < 0)
			*perm_err = true;
		minishell->commands->cmds[i]->redirection = redirect_in;
		close(minishell->commands->cmds[i]->descriptors->stdin);
		minishell->commands->cmds[i]->descriptors->stdin = fd;
	}
	else if (_equal(curr->val, ">>"))
	{
		fd = ft_open(curr->next->val, O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
		if (fd < 0)
			*perm_err = true;
		minishell->commands->cmds[i]->redirection = redirect_out;
		close(minishell->commands->cmds[i]->descriptors->stdout);
		minishell->commands->cmds[i]->descriptors->stdout = fd;
	}
	else
	{
		fd = ft_open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
		if (fd < 0)
			*perm_err = true;
		if (find_set(minishell->quote_tracker, curr->next))
			minishell->commands->cmds[i]->is_delim_quoted = true;
		minishell->commands->cmds[i]->redirection = redirect_heredoc;
		minishell->commands->cmds[i]->delim = ft_strdup(curr->next->val);
		close(minishell->commands->cmds[i]->descriptors->stdin);
		minishell->commands->cmds[i]->descriptors->stdin = fd;
	}
	curr = remove_node_lt(minishell->line, curr);
	return (remove_node_lt(minishell->line, curr));
}
