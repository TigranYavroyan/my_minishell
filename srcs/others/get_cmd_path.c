/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:08:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/29 20:49:13 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_path(t_minishell_ptr minishell);
static char	*get_path_exec(t_command_ptr command);

bool	access_cmd(t_command_ptr command)
{
	string	exec_path;

	exec_path = NULL;
	if (is_dir_util(command->name) && is_dir(command->name))
		return (false);
	exec_path = get_path_exec(command);
	if (exec_path == NULL)
	{
		__err_msg_prmt__(command->name, ": command not found", CMD_NOT_FOUND);
		return (false);
	}
	free(command->name);
	command->name = exec_path;
	exec_path = NULL;
	return (true);
}

static char	**get_path(t_minishell_ptr minishell)
{
	char	**res;
	char	*path;

	path = get_bst(minishell->env, "PATH");
	res = ft_split(path, ':');
	return (res);
}

static void	wait_and_status(pid_t pid, int *_status)
{
	waitpid(pid, _status, 0);
	if (WIFSIGNALED(*_status))
	{
		*_status = WTERMSIG(*_status) + 128;
		if (*_status == 131)
			write(1, "Quit: 3\n", 9);
		return (set_status_unsigned(*_status));
	}
	set_status_unsigned(WEXITSTATUS(*_status));
}

bool	_exec_util(char *full_path, t_command_ptr command, bool is_btin,
		int *fds UNUSED)
{
	char	**args;
	char	**env;
	pid_t	pid;
	int		sts;

	pid = fork();
	args = NULL;
	set_status_unsigned(VAL_CMD);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(fds[in]);
		if (is_btin)
			exec_builtin(command);
		else
		{
			push_front_lt(command->options, command->name);
			move_back_lt(&command->options, command->args);
			env = bst_to_matrix(command->minishell->env);
			args = list_to_matrix_lt(command->options);
			execve(full_path, args, env);
			set_status_unsigned(DIR_ERROR);
		}
		// have to free memory;
		exit(get_status());
	}
	wait_and_status(pid, &sts);
	remove_2d_str(args);
	return (true);
}

static char	*get_path_exec(t_command_ptr command)
{
	char	*tmp;
	char	*cmd;
	char	**path;
	int		i;

	i = -1;
	cmd = ft_strdup(command->name);
	if (!access(cmd, X_OK | F_OK))
		return (cmd);
	path = get_path(command->minishell);
	while (path && path[++i])
	{
		free(cmd);
		tmp = ft_strjoin(path[i], "/");
		cmd = ft_strjoin(tmp, command->name);
		free(tmp);
		if (!access(cmd, X_OK | F_OK))
		{
			remove_2d_str(path);
			return (cmd);
		}
	}
	remove_2d_str(path);
	free(cmd);
	return (NULL);
}
