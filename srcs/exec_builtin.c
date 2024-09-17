/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:00:49 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/17 19:10:35 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void exec_builtin (t_command_ptr command)
{
	const char* val;

	val = command->name;
	// if (_equal(val, "echo"))
	// 	ft_echo(command);
	// if (_equal(val, "cd"))
	// 	ft_cd(command);
	if (_equal(val, "pwd"))
		ft_pwd(command);
	if (_equal(val, "export"))
		ft_export(command);
	// if (_equal(val, "unset"))
	// 	ft_unset(command);
	if (_equal(val, "env"))
		ft_env(command);
	// if (_equal(val, "exit"))
	// 	ft_exit(command);
}