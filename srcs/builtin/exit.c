/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/15 18:22:56 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static long long	sh_atoll(const char *str, bool *plus)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '+')
			*plus = true;
		if (str[i] == '-')
			sign = (-1) * sign;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	return (sign * res);
}

static bool	ft_exit_util(t_command_ptr command)
{
	bool		plus;
	char		*real_val;
	long long	exit_status;

	plus = false;
	exit_status = sh_atoll(command->options->head->val, &plus);
	real_val = ft_lltoa(exit_status);
	if (exit_status && _equal(real_val, command->options->head->val + plus))
	{
		if (get_size(command->options) > 1)
		{
			__err_msg_prmt__("exit: ", "too many arguments", INV_ARG);
			free(real_val);
			return (false);
		}
		else
			set_status_unsigned(exit_status);
	}
	else
		__err_msg_full_prmt__("exit: ", command->options->head->val,
			": numeric argument required", EXIT_ERROR);
	free(real_val);
	return (true);
}

void	ft_exit(t_command_ptr command)
{
	bool	__exit__;

	move_back_lt(&command->options, command->args);
	ft_putstr_fd("exit\n", STDERR_FILENO);
	__exit__ = true;
	if (!empty_lt(command->options))
		__exit__ = ft_exit_util(command);
	if (__exit__)
	{
		clear_minishell(&command->minishell);
		exit(get_status());
	}
}
