/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:40 by tigran            #+#    #+#             */
/*   Updated: 2024/09/24 14:13:38 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_unset (t_command_ptr command)
{
	t_node_ptr	curr;

	if (!empty_lt(command->options) || empty_lt(command->args))
	{
		// ft_putstr_fd("Input is invalid\n", ERROR);// have to add correct error method
		return ;
	}
	curr = command->args->head;
	while (curr)
	{
		if (!is_var_name(curr->val, NULL))
			printf("minishell: unset: `%s': not a valid identifier\n", curr->val);// have to add correct error method
		else
		{
			remove_bst(command->minishell->env, curr->val);
			remove_bst(command->minishell->export, curr->val);
		}
		curr = curr->next;
	}
}