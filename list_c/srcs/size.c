/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:56:29 by tigran            #+#    #+#             */
/*   Updated: 2024/09/20 19:58:26 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int size_from_head_lt (t_node_ptr head)
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