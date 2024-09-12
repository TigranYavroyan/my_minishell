/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:42:26 by tigran            #+#    #+#             */
/*   Updated: 2024/09/12 20:17:59 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void update_quote_info (bool* open, char* opened_ch, t_node_ptr curr)
{
	if (is_quote(*curr->val))
	{
		if (!(*open))
		{
			*open = true;
			*opened_ch = *curr->val;
		}
		else if (*opened_ch == *curr->val)
		{
			*open = false;
			*opened_ch = 0;
		}
	}
}

void ft_remove_quotes(t_list_ptr line)
{
	bool		open;
	char		opened_ch;
	t_node_ptr	curr;

	open = false;
	curr = line->head;
	opened_ch = 0;
	while (curr)
	{
		if (open)
			printf("%s", curr->val);
		update_quote_info(&open, &opened_ch, curr); // add merge funtion
		curr = curr->next;
	}
}

static void update_stack (const t_node_ptr curr, t_list_ptr stack)
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
		update_stack(curr, stack);
		curr = curr->next;
	}
	
	if (empty_lt(stack))
		flag = true;
	clear_lt(stack);
	free(stack);
	return (flag);
}