/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:26 by tigran            #+#    #+#             */
/*   Updated: 2024/09/13 18:01:08 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void _update_stack (const t_node_ptr curr, t_list_ptr stack)
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

bool ft_quotes_check (t_list_ptr line)
{
	bool		flag;
	t_list_ptr	stack;
	t_node_ptr	curr;

	stack = init_lt();
	curr = line->head;
	flag = false;
	while (curr)
	{
		_update_stack(curr, stack);
		curr = curr->next;
	}
	
	if (empty_lt(stack))
		flag = true;
	clear_lt(stack);
	free(stack);
	return (flag);
}