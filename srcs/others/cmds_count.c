/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:23:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/16 16:27:14 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_count_cmds(t_minishell_ptr minishell)
{
	t_node_ptr	curr;

	curr = minishell->line->head;
	if (curr)
		++minishell->commands->size;
	while (curr)
	{
		if (_equal(curr->val, "|") && !find_set(minishell->quote_tracker, curr))
			++minishell->commands->size;
		curr = curr->next;
	}
}
