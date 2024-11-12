/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:00:49 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 18:03:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exec_builtin(t_command_ptr command)
{
	const char	*val;

	val = command->name;
	if (_equal(val, "echo"))
		ft_echo(command);
	if (_equal(val, "cd"))
		ft_cd(command);
	else if (_equal(val, "pwd"))
		ft_pwd(command);
	else if (_equal(val, "export"))
		ft_export(command);
	else if (_equal(val, "unset"))
		ft_unset(command);
	else if (_equal(val, "env"))
		ft_env(command);
	else if (_equal(val, "exit"))
		ft_exit(command);
}
