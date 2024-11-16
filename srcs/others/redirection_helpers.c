/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:00:55 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 15:45:44 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	_redirect_heredoc_util (t_minishell_ptr minishell, t_node_ptr curr, int* fd, int i)
{
	*fd = ft_open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	if (find_set(minishell->quote_tracker, curr->next))
		minishell->commands->cmds[i]->is_delim_quoted = true;
	if (*fd < 0)
		minishell->commands->cmds[i]->redirection = invalid_permission;
	else
		minishell->commands->cmds[i]->redirection = redirect_heredoc;
	minishell->commands->cmds[i]->delim = ft_strdup(curr->next->val);
	close(minishell->commands->cmds[i]->descriptors->stdin);
	minishell->commands->cmds[i]->descriptors->stdin = *fd;
}

static void	_redirect_out_util(t_minishell_ptr minishell, t_node_ptr curr, int* fd, int i)
{
	*fd = ft_open(curr->next->val, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
	if (*fd < 0)
		minishell->commands->cmds[i]->redirection = invalid_permission;
	else
		minishell->commands->cmds[i]->redirection = redirect_out;
	close(minishell->commands->cmds[i]->descriptors->stdout);
	minishell->commands->cmds[i]->descriptors->stdout = *fd;
}

static void	_redirect_in_util(t_minishell_ptr minishell, t_node_ptr curr, int* fd, int i)
{
	*fd = ft_open(curr->next->val, O_RDONLY, FILE_PERM);
	if (*fd < 0)
		minishell->commands->cmds[i]->redirection = invalid_permission;
	else
		minishell->commands->cmds[i]->redirection = redirect_in;
	close(minishell->commands->cmds[i]->descriptors->stdin);
	minishell->commands->cmds[i]->descriptors->stdin = *fd;
}

static void	_redirect_out_append_util(t_minishell_ptr minishell, t_node_ptr curr, int* fd, int i)
{
	*fd = ft_open(curr->next->val, O_WRONLY | O_CREAT | O_APPEND, FILE_PERM);
	if (*fd < 0)
		minishell->commands->cmds[i]->redirection = invalid_permission;
	else
		minishell->commands->cmds[i]->redirection = redirect_out;
	close(minishell->commands->cmds[i]->descriptors->stdout);
	minishell->commands->cmds[i]->descriptors->stdout = *fd;
}

t_node_ptr	__redirect_handle(t_minishell_ptr minishell, t_node_ptr curr, int i)
{
	int	fd;

	if (_equal(curr->val, ">"))
		_redirect_out_util(minishell, curr, &fd, i);
	else if (_equal(curr->val, "<"))
		_redirect_in_util(minishell, curr, &fd, i);
	else if (_equal(curr->val, ">>"))
		_redirect_out_append_util(minishell, curr, &fd, i);
	else
		_redirect_heredoc_util(minishell, curr, &fd, i);
	curr = remove_node_lt(minishell->line, curr);
	return (remove_node_lt(minishell->line, curr));
}
