/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:08:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/21 15:49:43 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char**	get_path (t_minishell_ptr minishell)
{
	char**	res;
	char*	path;

	path = get_bst(minishell->env, "PATH");
	res = ft_split(path, ':');
	return (res);
}

static bool exec (char* full_path, t_command_ptr command)
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
			ft_putstr_fd("execve failure\n", ERROR);
		}
		else
			waitpid(pid, NULL, 0); // check
		remove_2d_str(args);
		return (true);
	}
	return (false);
}

bool	access_cmd(t_command_ptr command)
{
	char	**path;
	char	*full_path;
	int		i;

	path = get_path(command->minishell);
	i = -1;
	while (path[++i] != NULL)
	{
		full_path = ft_strjoin(path[i], "/");
		ft_append(&full_path, command->name);
		if (exec(full_path, command))
		{
			free(full_path);
			break;
		}
		free(full_path);
	}
	remove_2d_str(path);
	return (true);
}