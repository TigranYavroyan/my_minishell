/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:17:24 by tigpetro          #+#    #+#             */
/*   Updated: 2024/08/18 16:54:03 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	remove_if_lt(t_list_ptr list, char *val)
{
	t_node	*curr;
	t_node	*tmp;

	if (empty_lt(list))
		return ;
	curr = list->head;
	while (curr)
	{
		tmp = curr->next;
		if (diff_lt(curr->val, val))
			remove_node_lt(list, curr);
		curr = tmp;
	}
}

void	remove_if_range_lt(t_list_ptr list, t_node *start, t_node *end,
		char *val)
{
	t_node	*curr;
	t_node	*tmp;

	if (empty_lt(list))
		return ;
	curr = start;
	while (curr != end)
	{
		tmp = curr->next;
		if (diff_lt(curr->val, val))
			remove_node_lt(list, curr);
		curr = tmp;
	}
}
