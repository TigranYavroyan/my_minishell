/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ctor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:25:58 by tyavroya          #+#    #+#             */
/*   Updated: 2024/08/22 12:33:01 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	copy_lt(t_list_ptr this, t_list_ptr other)
{
	t_node	*curr;

	curr = other->head;
	while (curr)
	{
		push_back_lt(this, curr->val);
		curr = curr->next;
	}
	this->size = other->size;
}

void	copy_range_lt(t_list_ptr this, t_node *node, t_node *end)
{
	if (!node)
	{
		push_back_lt(this, "");
		return ;
	}
	while (node && node != end)
	{
		push_back_lt(this, node->val);
		this->size++;
		node = node->next;
	}
}
