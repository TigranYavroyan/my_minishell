/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:25:40 by tyavroya          #+#    #+#             */
/*   Updated: 2024/08/19 20:45:56 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

bool	diff_lt(char *word, char *to_cmp)
{
	int	i;

	i = 0;
	while (word[i] && to_cmp[i])
	{
		if (word[i] != to_cmp[i])
			return (false);
		++i;
	}
	if (word[i] == to_cmp[i])
		return (true);
	return (false);
}

t_node	*find_word_range_lt(t_node *curr, t_node *end, char *word)
{
	if (curr == end)
		return (end);
	while (curr != end)
	{
		if (diff_lt(curr->val, word))
			return (curr);
		curr = curr->next;
	}
	return (end);
}

t_node	*find_word_lt(t_node *curr, char *word)
{
	while (curr)
	{
		if (diff_lt(curr->val, word))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

t_node	*find_word_if_lt(t_node *curr, bool (*p)(char *))
{
	while (curr)
	{
		if (p(curr->val) == true)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int	find_index_lt(t_list_ptr list, t_node *to_find)
{
	int		res;
	t_node	*curr;

	res = 0;
	if (empty_lt(list))
		return (res);
	curr = list->head;
	while (curr && curr != to_find)
	{
		curr = curr->next;
		++res;
	}
	return (res);
}
