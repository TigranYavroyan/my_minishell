/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:40 by tigran            #+#    #+#             */
/*   Updated: 2024/09/20 21:35:00 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_unset (t_command_ptr command)
{
	t_node_ptr	curr;

	if (!empty_lt(command->options) || empty_lt(command->args))
	{
		ft_putstr_fd("Input is invalid\n", ERROR);
		return ;
	}
	curr = command->args->head;
	while (curr)
	{
		remove_bst(command->minishell->env, curr->val);
		remove_bst(command->minishell->export, curr->val);
		curr = curr->next;
	}
}