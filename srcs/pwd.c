/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:29 by tigran            #+#    #+#             */
/*   Updated: 2024/09/24 14:39:41 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_pwd(t_command_ptr command)
{
	char	cwd[PATH_MAX];
	char*	invalid_option;

	if (!empty_lt(command->options))
	{
		invalid_option = command->options->head->val;
		ft_append(&invalid_option, ": invalid option");
		__err_msg_prmt__("pwd", invalid_option, INV_OPTION);
		free(invalid_option);
	}
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd() error");
}