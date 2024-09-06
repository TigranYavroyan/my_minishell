/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:50 by tyavroya          #+#    #+#             */
/*   Updated: 2024/08/18 16:56:45 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	free_node(t_node **node)
{
	free((*node)->val);
	free(*node);
}

t_node	*make_node(char *str)
{
	int		i;
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->val = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = -1;
	while (str[++i])
		node->val[i] = str[i];
	node->val[i] = '\0';
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	print_lt(t_list_ptr list)
{
	t_node	*curr;

	curr = list->head;
	while (curr)
	{
		printf("%s\n", curr->val);
		curr = curr->next;
	}
}
