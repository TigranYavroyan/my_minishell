/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ctor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:25:58 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/07 14:10:38 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list_ptr	copy_lt(t_list_ptr other)
{
	t_list_ptr this;
	t_node	*curr;

	this = init_lt();
	curr = other->head;
	while (curr)
	{
		push_back_lt(this, curr->val);
		curr = curr->next;
	}
	this->size = other->size;
	return this;
}

t_list_ptr	copy_range_lt(t_node *node, t_node *end)
{
	t_list_ptr this;

	this = init_lt();
	if (!node)
	{
		push_back_lt(this, "");
		return this;
	}
	while (node && node != end)
	{
		push_back_lt(this, node->val);
		this->size++;
		node = node->next;
	}
	return this;
}
