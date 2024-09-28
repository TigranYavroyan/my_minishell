/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:50:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/28 20:55:21 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void execute (t_minishell_ptr minishell)
{
	int		i;
	int		fds[2];
	bool	is_btin;

	i = -1;
	while (++i < minishell->commands->size)
	{
		if (pipe(fds) < 0)
			return (ft_err_msg("fork: Resource temporarily unavailable"));
		is_btin = is_builtin(minishell->commands->cmds[i]->name);
		// dup manipulation here with helper function
		if (minishell->commands->size == 1 && is_btin)
			exec_builtin(minishell->commands->cmds[i]);
		else if (is_btin || access_cmd(minishell->commands->cmds[i]))
			_exec_util(minishell->commands->cmds[i]->name, minishell->commands->cmds[i]);
	}
}