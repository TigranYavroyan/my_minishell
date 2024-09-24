/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:11 by tigran            #+#    #+#             */
/*   Updated: 2024/09/24 17:38:54 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_exit(t_command_ptr command)
{
	char*	arg;

	move_back_lt(&command->options, command->args);
	if (!empty_lt(command->options))
	{
		if (is_num_str(command->options->head->val))
		{
			if (get_size(command->options) > 1)
			{
				__err_msg_prmt__("exit: ", "too many arguments", INV_ARG);
				return ;
			}
			else
				set_status_unsigned(ft_atoi(command->options->head->val));
		}
		else
		{
			arg = ft_strdup(command->options->head->val);
			ft_append(&arg, ": numeric argument required");
			__err_msg_prmt__("exit: ", arg, INV_OPTION);
			free(arg);
		}
	}
	clear_minishell(&command->minishell);
	exit(get_status());
}