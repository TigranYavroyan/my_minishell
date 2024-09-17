/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:23:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/17 18:44:26 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_count_cmds (t_minishell_ptr minishell)
{
	t_node_ptr	curr;

	curr = minishell->line->head;
	if (curr)
		++minishell->commands->size;
	while (curr)
	{
		if (_equal(curr->val, "|"))
			++minishell->commands->size;
		curr = curr->next;
	}
}