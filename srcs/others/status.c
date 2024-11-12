/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:04:41 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 17:51:20 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		g_status;

void	set_status_unsigned(int status)
{
	g_status = (const unsigned char)status;
}

void	set_status_signed(int status)
{
	g_status = (const char)status;
}

void	set_status_int(int status)
{
	g_status = status;
}

int	get_status(void)
{
	return (g_status);
}
