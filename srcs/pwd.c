/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:29 by tigran            #+#    #+#             */
/*   Updated: 2024/09/17 19:02:04 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_pwd(t_command_ptr command UNUSED)
{
	char	cwd[PATH_MAX];

	if (!empty_lt(command->args) || !empty_lt(command->options))
		ft_putstr_fd("pwd: too many arguments\n", ERROR);
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd() error");
}