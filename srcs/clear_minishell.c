/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:26 by tigran            #+#    #+#             */
/*   Updated: 2024/09/29 20:48:22 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void clear_minishell(t_minishell_ptr* minishell)
{
	t_minishell_ptr	tmp;

	tmp = *minishell;
	clear_lt((*minishell)->line);
	free((*minishell)->line);

	clear_bst(&(*minishell)->env);
	clear_bst(&(*minishell)->export);
	clear_cmds((*minishell)->commands);
	free(tmp->commands);
	// close((*minishell)->descriptors->stdin);
	// close((*minishell)->descriptors->stdout);
	// close((*minishell)->descriptors->stderr);
	free((*minishell)->descriptors);
	free(tmp);
}