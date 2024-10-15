/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:29 by tigran            #+#    #+#             */
/*   Updated: 2024/10/10 18:56:33 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_pwd(t_command_ptr command)
{
	char	cwd[PATH_MAX];

	if (!empty_lt(command->options))
		__err_msg_full_prmt__("pwd: ", command->options->head->val, ": invalid option", INV_ARG);
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd() error");
}