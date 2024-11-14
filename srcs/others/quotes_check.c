/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:26 by tigran            #+#    #+#             */
/*   Updated: 2024/11/14 14:58:42 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	_update_stack(const t_node_ptr curr, t_list_ptr stack)
{
	if (_equal(curr->val, "\""))
	{
		if (empty_lt(stack) || !_equal(stack->tail->val, "\""))
			push_back_lt(stack, "\"");
		else if (_equal(stack->tail->val, "\""))
			pop_back_lt(stack);
	}
	else if (_equal(curr->val, "\'"))
	{
		if (empty_lt(stack) || !_equal(stack->tail->val, "\'"))
			push_back_lt(stack, "\'");
		else if (_equal(stack->tail->val, "\'"))
			pop_back_lt(stack);
	}
}

bool	ft_quotes_check(t_list_ptr line, t_set_ptr quote_tracker)
{
	bool		flag;
	t_list_ptr	stack;
	t_node_ptr	curr;

	stack = init_lt();
	curr = line->head;
	flag = true;
	while (curr)
	{
		if (!find_set(quote_tracker, curr))
			_update_stack(curr, stack);
		curr = curr->next;
	}
	if (!empty_lt(stack))
		flag = false;
	clear_lt(stack);
	free(stack);
	return (flag);
}
