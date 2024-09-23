/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:43:10 by tigran            #+#    #+#             */
/*   Updated: 2024/09/23 21:52:51 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void remove_2d_str (char** str)
{
	int	i;

	i = -1;
	while (str && str[++i] != NULL)
		free(str[i]);
	free(str);
}

bool is_quote(char ch)
{
	return (ch == '\'' || ch == '\"');
}

void	ft_err_msg(char *msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
}

void __exit__(const char* name, const char* err, unsigned int val)
{
	ft_err_msg(NULL);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putendl_fd(err, STDERR_FILENO);
	set_status_unsigned(val);
}