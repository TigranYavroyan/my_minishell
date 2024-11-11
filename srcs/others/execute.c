/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:50:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/11 19:19:47 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void eval(t_cmd_matrix_ptr commands, int* fds, int i)
{
	bool	is_btin;

	is_btin = is_builtin(commands->cmds[i]->name);
	if (i < commands->size - 1)
		dup2(fds[out], STDOUT_FILENO);
	if (commands->cmds[i]->redirection == redirect_out)
		dup2(commands->cmds[i]->descriptors->stdout, STDOUT_FILENO);
	else if (commands->cmds[i]->redirection == redirect_in)
		dup2(commands->cmds[i]->descriptors->stdin, STDIN_FILENO);
	// henrik implement from here
	else if (commands->cmds[i]->redirection == redirect_heredoc)
		heredoc_handle(commands->cmds[i]); // <--
	// to here
	if (commands->size == 1 && is_btin)
		exec_builtin(commands->cmds[i]);
	else if (is_btin || access_cmd(commands->cmds[i]))
		_exec_util(commands->cmds[i], is_btin, fds, i);
	dup2(fds[in], STDIN_FILENO);
	dup2(commands->minishell->descriptors->stdout, STDOUT_FILENO);
	close(fds[in]);
	close(fds[out]);
	refresh_descriptors(commands->cmds[i]);
}

void execute (t_minishell_ptr minishell)
{
	int		i;
	int		fds[2];

	i = -1;
	while (++i < minishell->commands->size)
	{
		if (pipe(fds) < 0)
			return (__err_msg_prmt__("fork: ", "Resource temporarily unavailable", FORK_ERROR));
		eval(minishell->commands, fds, i);
	}
	dup2(minishell->descriptors->stdin, STDIN_FILENO);
	while (-1 != wait(NULL))
		;
}