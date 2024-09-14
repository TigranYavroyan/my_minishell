/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:06:24 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/14 21:47:54 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd_matrix_ptr	init_cmds(t_minishell_ptr minishell)
{
	t_cmd_matrix_ptr commands;

	commands = (t_cmd_matrix_ptr)wrapper_malloc(sizeof(t_cmd_matrix));
	commands->cmds = NULL;
	commands->minishell = minishell;
	commands->size = 0;
	return (commands);
}

static void	init_cmd(t_cmd_matrix_ptr cmds)
{
	int	i;

	i = -1;
	cmds->cmds = (t_command_ptr*)wrapper_malloc(sizeof(t_command_ptr));
	while (++i < cmds->size)
		cmds->cmds[i] = (t_command_ptr)wrapper_malloc(sizeof(t_command));
}

void	clear_cmds(t_cmd_matrix_ptr commands)
{
	int	i;

	i = -1;
	while (++i < commands->size)
		free(commands->cmds[i]);
	free(commands->cmds);
	commands->size = 0;
	commands->cmds = NULL;
}

void	get_cmds(t_minishell_ptr minishell)
{
	init_cmd(minishell->commands);
}