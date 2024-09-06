/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:40:20 by tyavroya          #+#    #+#             */
/*   Updated: 2024/08/18 16:54:14 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	init_lt(t_list_ptr list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

bool	empty_lt(t_list_ptr list)
{
	return (list == NULL || list->head == NULL);
}

char	*at_lt(t_list_ptr list, int index)
{
	t_node	*curr;

	if (index < 0 || index >= list->size)
		_err("Error: Out of range");
	curr = list->head;
	while (index--)
		curr = curr->next;
	return (curr->val);
}

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

int	value_counter_lt(t_list_ptr list, char *src)
{
	t_node	*tmp;
	int		res;

	tmp = list->head;
	res = 0;
	while (tmp)
	{
		if (!ft_strncmp(tmp->val, src, sizeof(tmp->val)))
			++res;
		tmp = tmp->next;
	}
	return (res);
}
