/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:11 by tigran            #+#    #+#             */
/*   Updated: 2024/10/10 18:23:10 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_exit(t_command_ptr command) // have to quotes checking and passing
{
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
			__err_msg_full_prmt__("exit: ", command->options->head->val, ": numeric argument required", EXIT_ERROR);
	}
	clear_minishell(&command->minishell);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	exit(get_status());
}