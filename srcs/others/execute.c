/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:50:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/20 18:12:49 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	restore_std_files_begin(void)
{
	int	tty_fd;

	tty_fd = ft_open("/dev/tty", O_RDWR, 0666);
	if (tty_fd == -1)
		exit(1);
	dup2(tty_fd, STDIN_FILENO);
	dup2(tty_fd, STDOUT_FILENO);
	dup2(tty_fd, STDERR_FILENO);
	close(tty_fd);
}

static void	restore_std_files_end(t_descriptors_ptr old_fds)
{
	dup2(old_fds->stdout, STDOUT_FILENO);
	dup2(old_fds->stderr, STDERR_FILENO);
	close(old_fds->stdout);
	close(old_fds->stdin);
	close(old_fds->stderr);
}

static void	redir_checker(t_cmd_matrix_ptr commands, int i, bool *exec_flag,
		int *fds)
{
	t_descriptors_ptr	old_fds;

	if ((commands->cmds[i]->redirection & redirect_heredoc) == redirect_heredoc)
	{
		old_fds = make_descriptors();
		restore_std_files_begin();
		*exec_flag = heredoc_handle(commands->cmds[i], fds, i);
		restore_std_files_end(old_fds);
		free(old_fds);
	}
	if ((commands->cmds[i]->redirection & redirect_out) == redirect_out)
		dup2(commands->cmds[i]->descriptors->stdout, STDOUT_FILENO);
	if ((commands->cmds[i]->redirection & redirect_in) == redirect_in)
		dup2(commands->cmds[i]->descriptors->stdin, STDIN_FILENO);
}

static void	eval(t_cmd_matrix_ptr commands, int *fds, int i)
{
	bool	is_btin;
	bool	exec_flag;

	exec_flag = true;
	is_btin = is_builtin(commands->cmds[i]->name);
	if (*(commands->cmds[i]->name) == 0
		&& !((commands->cmds[i]->redirection
				& redirect_heredoc) == redirect_heredoc))
		return ;
	if (i < commands->size - 1)
		dup2(fds[out], STDOUT_FILENO);
	if (commands->cmds[i]->redirection != invalid_permission)
	{
		redir_checker(commands, i, &exec_flag, fds);
		if (commands->size == 1 && is_btin && exec_flag)
			exec_builtin(commands->cmds[i]);
		else if ((is_btin || access_cmd(commands->cmds[i])) && exec_flag)
			_exec_util(commands->cmds[i], is_btin, fds, i);
	}
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
			return (__err_msg_prmt__("fork: ", HEREDOC_ERR_MSG, FORK_ERROR));
		eval(minishell->commands, fds, i);
		if ((minishell->commands->cmds[i]->redirection
				& redirect_heredoc) == redirect_heredoc)
			unlink(HEREDOC_FILE);
	}
	dup2(minishell->descriptors->stdin, STDIN_FILENO);
	while (-1 != wait(NULL))
		;
}
