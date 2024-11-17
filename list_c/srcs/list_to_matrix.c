/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:54:21 by tigran            #+#    #+#             */
/*   Updated: 2024/11/17 17:38:56 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

char	**list_to_matrix_lt(t_list_ptr list)
{
	t_node	*tmp;
	char	**res;
	int		size;
	int		i;

	size = list->size;
	res = wrapper_malloc(sizeof(char *) * (size + 1));
	res[size] = NULL;
	i = -1;
	tmp = list->head;
	while (++i < size && tmp)
	{
		res[i] = ft_strdup(tmp->val);
		tmp = tmp->next;
	}
	return (res);
}

char	**from_head_to_matrix_lt(t_node_ptr head)
{
	char	**res;
	int		size;
	int		i;

	size = size_from_head_lt(head);
	res = wrapper_malloc(sizeof(char *) * (size + 1));
	res[size] = NULL;
	i = -1;
	while (++i < size && head)
	{
		res[i] = ft_strdup(head->val);
		head = head->next;
	}
	return (res);
}
