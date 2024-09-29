/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:08:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/29 20:57:48 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char**	get_path (t_minishell_ptr minishell);
static char*	get_path_exec(t_command_ptr command);

bool	access_cmd(t_command_ptr command)
{
	string	exec_path;

	exec_path = get_path_exec(command);
	if (exec_path == NULL)
	{
		__err_msg_prmt__(command->name, ": command not found", CMD_NOT_FOUND);
		return (false);
	}
	if (is_dir(exec_path))
		return (false);
	free(command->name);
	command->name = exec_path;
	exec_path = NULL;
	return (true);
}

static char**	get_path (t_minishell_ptr minishell)
{
	char**	res;
	char*	path;

	path = get_bst(minishell->env, "PATH");
	res = ft_split(path, ':');
	return (res);
}

bool	_exec_util (char* full_path, t_command_ptr command, bool is_btin, int* fds UNUSED)
{
	char		**args;
	char		**env;
	pid_t		pid;

	pid = fork();
	args = NULL;
	if (pid == 0)
	{
		close(fds[in]);
		if (is_btin)
			exec_builtin(command);
		else {
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
	waitpid(pid, NULL, 0); // check
	remove_2d_str(args);
	return (true);
}

static char*	get_path_exec(t_command_ptr command)
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
