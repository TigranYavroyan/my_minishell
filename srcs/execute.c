/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:50:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/19 13:52:55 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void execute (t_minishell_ptr minishell)
{
	int	i;

	i = -1;
	while (++i < minishell->commands->size)
	{
		if (is_builtin(minishell->commands->cmds[i]->name))
			exec_builtin(minishell->commands->cmds[i]);
		else
			access_cmd(minishell->commands->cmds[i]);
	}
}