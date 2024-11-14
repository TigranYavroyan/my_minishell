/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/14 21:42:05 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exit(t_command_ptr command)
{
	long long	exit_status;
	char		*real_val;

	move_back_lt(&command->options, command->args);
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (!empty_lt(command->options))
	{
		exit_status = ft_atoll(command->options->head->val);
		real_val = ft_lltoa(exit_status);
		if (exit_status && _equal(real_val, command->options->head->val))
		{
			if (get_size(command->options) > 1)
			{
				__err_msg_prmt__("exit: ", "too many arguments", INV_ARG);
				free(real_val);
				return ;
			}
			else
				set_status_unsigned(exit_status);
		}
		else
			__err_msg_full_prmt__("exit: ", command->options->head->val,
				": numeric argument required", EXIT_ERROR);
		free(real_val);
	}
	clear_minishell(&command->minishell);
	exit(get_status());
}
