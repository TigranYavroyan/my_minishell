/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:08:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/24 17:39:41 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char**	get_path (t_minishell_ptr minishell);
static bool		_exec_util (char* full_path, t_command_ptr command);
static bool		exec(t_command_ptr command, char **path, int i);

static bool	exec(t_command_ptr command, char **path, int i)
{
	char*	full_path;

	if (access(command->name, X_OK) != 0)
	{
		full_path = ft_strjoin(path[i], "/");
		ft_append(&full_path, command->name);
	}
	else
		full_path = ft_strdup(command->name);
	if (_exec_util(full_path, command))
	{
		free(full_path);
		return (true);
	}
	free(full_path);
	return (false);
}

bool	access_cmd(t_command_ptr command)
{
	char	**path;
	int		i;
	bool	status;

	path = get_path(command->minishell);
	i = -1;
	status = false;
	while (path[++i] != NULL)
	{
		if (exec(command, path, i))
		{
			status = true;
			break;
		}
	}
	if (status == false)
		__err_msg__(command->name, ": command not found", CMD_NOT_FOUND);
	remove_2d_str(path);
	return (status);
}

static char**	get_path (t_minishell_ptr minishell)
{
	char**	res;
	char*	path;

	path = get_bst(minishell->env, "PATH");
	res = ft_split(path, ':');
	return (res);
}

static bool _exec_util (char* full_path, t_command_ptr command)
{
	char		**args;
	char		**env;
	pid_t		pid;

	if (access(full_path, X_OK) == 0)
	{
		pid = fork();
		args = NULL;
		if (pid == 0)
		{
			push_front_lt(command->options, command->name);
			move_back_lt(&command->options, command->args);
			env = bst_to_matrix(command->minishell->env);
			args = list_to_matrix_lt(command->options);
			execve(full_path, args, env);
			exit(DIR_ERROR);
		}
		else
			// waitpid(pid, NULL, 0); // check
			wait(NULL);
		remove_2d_str(args);
		return (true);
	}
	return (false);
}