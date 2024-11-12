/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:11 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 18:03:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_err_msg(char *msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
}

void	__err_msg__(char *name, char *err, int err_val)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putendl_fd(err, STDERR_FILENO);
	set_status_unsigned(err_val);
}

void	__err_msg_prmt__(char *name, char *err, int err_val)
{
	ft_err_msg(NULL);
	__err_msg__(name, err, err_val);
}

void	__err_msg_full__(char *name, char *err, char *reason, int err_val)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(err, STDERR_FILENO);
	ft_putendl_fd(reason, STDERR_FILENO);
	set_status_unsigned(err_val);
}

void	__err_msg_full_prmt__(char *name, char *err, char *reason, int err_val)
{
	ft_err_msg(NULL);
	__err_msg_full__(name, err, reason, err_val);
}
