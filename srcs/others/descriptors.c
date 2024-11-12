/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:01:36 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 18:03:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_descriptors_ptr	make_descriptors(void)
{
	t_descriptors_ptr	dskt;

	dskt = wrapper_malloc(sizeof(t_descriptors));
	dskt->stdin = dup(STDIN_FILENO);
	dskt->stdout = dup(STDOUT_FILENO);
	dskt->stderr = dup(STDERR_FILENO);
	return (dskt);
}

void	refresh_descriptors(t_command_ptr command)
{
	if (!command || !command->minishell)
		return ;
	if (command->minishell->descriptors->stdout != command->descriptors->stdout)
		dup2(command->minishell->descriptors->stdout,
			command->descriptors->stdout);
	if (command->minishell->descriptors->stdin != command->descriptors->stdin)
		dup2(command->minishell->descriptors->stdin,
			command->descriptors->stdin);
	if (command->minishell->descriptors->stderr != command->descriptors->stderr)
		dup2(command->minishell->descriptors->stderr,
			command->descriptors->stderr);
}
