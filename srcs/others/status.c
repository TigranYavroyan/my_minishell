/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:04:41 by tigran            #+#    #+#             */
/*   Updated: 2024/09/24 15:23:11 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	g_status;

void	set_status_unsigned(int status)
{
	g_status = (const unsigned char)status;
}

void	set_status_signed(int status)
{
	g_status = (const char)status;
}

int	get_status ()
{
	return (g_status);
}