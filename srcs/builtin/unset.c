/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:40 by tigran            #+#    #+#             */
/*   Updated: 2024/10/10 19:01:13 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_unset (t_command_ptr command)
{
	t_node_ptr	curr;

	if (!empty_lt(command->options) || empty_lt(command->args))
	{
		__err_msg_full_prmt__("unset: ", command->options->head->val, ": invalid option", INV_OPTION);
		return ;
	}
	curr = command->args->head;
	while (curr)
	{
		if (!is_var_name(curr->val, NULL))
			__err_msg_full_prmt__("unset: `", curr->val, "\': not a valid identifier", INV_ARG);
		else
		{
			remove_bst(command->minishell->env, curr->val);
			remove_bst(command->minishell->export, curr->val);
		}
		curr = curr->next;
	}
}