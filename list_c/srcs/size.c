/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:56:29 by tigran            #+#    #+#             */
/*   Updated: 2024/09/29 15:26:13 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	size_from_head_lt(t_node_ptr head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		++size;
	}
	return (size);
}

int	get_size(t_list_ptr list)
{
	return (list->size);
}
