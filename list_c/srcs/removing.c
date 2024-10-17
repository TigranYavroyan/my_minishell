/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:46 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/17 18:34:06 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_node_ptr	remove_node_lt(t_list_ptr list, t_node *node)
{
	t_node_ptr	tmp;

	if (!node)
		return (NULL);
	tmp = node->next;
	if (node == list->head)
		pop_front_lt(list);
	else if (node == list->tail)
		pop_back_lt(list);
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free_node(&node);
		--(list->size);
	}
	return (tmp);
}

void	remove_index_node_lt(t_list_ptr list, int index)
{
	t_node	*curr;
	t_node	*to_delete;

	if (index < 0 || index >= list->size || empty_lt(list))
		_err("Error: Out of range");
	if (index == 0)
		pop_front_lt(list);
	else if ((index + 1) == list->size)
		pop_back_lt(list);
	else
	{
		curr = list->head;
		while (index--)
			curr = curr->next;
		to_delete = curr;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		free_node(&to_delete);
		--(list->size);
	}
}

void	pop_back_lt(t_list_ptr list)
{
	t_node	*curr;

	if (!empty_lt(list))
	{
		if (list->size == 1)
		{
			free_node(&(list->head));
			list->head = NULL;
			list->tail = NULL;
		}
		else
		{
			curr = list->tail;
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			free_node(&curr);
		}
		--(list->size);
	}
	else
		printf("The list is empty\n");
}

void	pop_front_lt(t_list_ptr list)
{
	t_node	*curr;

	if (!empty_lt(list))
	{
		if (list->size == 1)
		{
			free_node(&(list->head));
			list->head = NULL;
			list->tail = NULL;
		}
		else
		{
			curr = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			free_node(&curr);
		}
		--(list->size);
	}
	else
		printf("The list is empty\n");
}

void	clear_lt(t_list_ptr list)
{
	t_node	*curr;

	if (!list)
		return ;
	curr = list->head;
	while (curr)
	{
		list->head = list->head->next;
		free_node(&curr);
		curr = list->head;
	}
	list->size = 0;
}
