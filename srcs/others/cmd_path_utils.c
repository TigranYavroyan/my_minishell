/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:17:44 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/15 15:21:17 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exec_path_util(t_command_ptr command, bool is_btin, int *fds)
{
	char	**args;
	char	**env;

	args = NULL;
	env = NULL;
	set_status_unsigned(VAL_CMD);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(fds[in]);
	close(fds[out]);
	if (is_btin)
		exec_builtin(command);
	else
	{
		push_front_lt(command->options, command->name);
		move_back_lt(&command->options, command->args);
		env = bst_to_matrix(command->minishell->env);
		args = list_to_matrix_lt(command->options);
		execve(command->name, args, env);
		set_status_unsigned(DIR_ERROR);
	}
	clear_minishell(&command->minishell);
	remove_2d_str(env);
	remove_2d_str(args);
	exit(get_status());
}
