/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:03:40 by tigran            #+#    #+#             */
/*   Updated: 2024/09/16 20:14:09 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool pipe_check (t_list_ptr line)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr)
	{	
		if (_equal(curr->val, "|"))
		{
			if (curr->prev == NULL)
				return (false);
			curr = curr->next;
			while (curr && ft_isspace(*curr->val))
				curr = curr->next;
			if (!curr || !ft_isalpha(*curr->val))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}