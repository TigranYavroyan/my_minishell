/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:40 by tigran            #+#    #+#             */
/*   Updated: 2024/10/22 20:07:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unset(t_command_ptr command)
{
	t_node_ptr	curr;

	if (!empty_lt(command->options) || empty_lt(command->args))
		return ;
	curr = command->args->head;
	while (curr)
	{
		if (!is_var_name(curr->val, NULL))
			__err_msg_full_prmt__("unset: `", curr->val,
				"\': not a valid identifier", INV_ARG);
		else
		{
			remove_bst(command->minishell->env, curr->val);
			remove_bst(command->minishell->export, curr->val);
		}
		curr = curr->next;
	}
}
