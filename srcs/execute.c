/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:50:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/28 18:17:53 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void execute (t_minishell_ptr minishell)
{
	int	i;
	int	fds[2];

	i = -1;
	while (++i < minishell->commands->size)
	{
		if (pipe(fds) < 0)
			return (ft_err_msg("fork: Resource temporarily unavailable"));
		if (is_builtin(minishell->commands->cmds[i]->name))
			exec_builtin(minishell->commands->cmds[i]);
		else
			access_cmd(minishell->commands->cmds[i]);
	}
}