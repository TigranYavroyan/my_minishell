/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:50:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 18:02:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	eval(t_cmd_matrix_ptr commands, int *fds, int i)
{
	bool	is_btin;
	bool	exec_flag;

	exec_flag = true;
	is_btin = is_builtin(commands->cmds[i]->name);
	if (i < commands->size - 1)
		dup2(fds[out], STDOUT_FILENO);
	if (commands->cmds[i]->redirection == redirect_out)
		dup2(commands->cmds[i]->descriptors->stdout, STDOUT_FILENO);
	else if (commands->cmds[i]->redirection == redirect_in)
		dup2(commands->cmds[i]->descriptors->stdin, STDIN_FILENO);
	else if (commands->cmds[i]->redirection == redirect_heredoc)
		exec_flag = heredoc_handle(commands->cmds[i]);
	if (commands->size == 1 && is_btin && exec_flag)
		exec_builtin(commands->cmds[i]);
	else if ((is_btin || access_cmd(commands->cmds[i])) && exec_flag)
		_exec_util(commands->cmds[i], is_btin, fds, i);
	dup2(fds[in], STDIN_FILENO);
	dup2(commands->minishell->descriptors->stdout, STDOUT_FILENO);
	close(fds[in]);
	close(fds[out]);
	refresh_descriptors(commands->cmds[i]);
}

void	execute(t_minishell_ptr minishell)
{
	int	i;
	int	fds[2];

	i = -1;
	while (++i < minishell->commands->size)
	{
		if (pipe(fds) < 0)
			return (__err_msg_prmt__("fork: ",
					"Resource temporarily unavailable", FORK_ERROR));
		eval(minishell->commands, fds, i);
		if (minishell->commands->cmds[i]->redirection == redirect_heredoc)
			unlink(HEREDOC_FILE);
	}
	dup2(minishell->descriptors->stdin, STDIN_FILENO);
	while (-1 != wait(NULL))
		;
}
