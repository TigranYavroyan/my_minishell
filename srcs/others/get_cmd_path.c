/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:08:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/15 17:39:46 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_path(t_minishell_ptr minishell);
static char	*get_path_exec(t_command_ptr command);

bool	access_cmd(t_command_ptr command)
{
	struct stat	info;
	int			status;

	__attribute__((cleanup(auto_free))) char *exec_path;
	status = stat(command->name, &info);
	exec_path = NULL;
	if (is_dir_util(command->name) && is_dir(command->name, &info, status))
		return (false);
	if (is_dir_util(command->name) && S_ISREG(info.st_mode)
		&& !(info.st_mode & S_IXUSR))
	{
		__err_msg_prmt__(command->name, ": Permission denied", DIR_ERROR);
		return (false);
	}
	exec_path = get_path_exec(command);
	if (exec_path == NULL || S_ISDIR(info.st_mode))
	{
		__err_msg_prmt__(command->name, ": command not found", CMD_NOT_FOUND);
		// printf("gegham\n");
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

void	_exec_util(t_command_ptr command, bool is_btin, int *fds, int i)
{
	pid_t	pid;
	int		sts;

	pid = fork();
	if (pid == -1)
		return (__err_msg_prmt__("fork: ", HEREDOC_ERR_MSG, FORK_ERROR));
	if (pid == 0)
		exec_path_util(command, is_btin, fds);
	if (i == command->minishell->commands->size - 1)
		wait_and_status(pid, &sts);
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
