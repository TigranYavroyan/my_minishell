/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:37:48 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 22:55:29 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_merge_quotes(t_minishell_ptr minishell)
{
	char		opened_ch;
	bool		open;
	t_node_ptr	curr;
	t_node_ptr	tmp;

	curr = minishell->line->head;
	while (curr)
	{
		_update_quote_info(&open, &opened_ch, curr);
		if (open)
		{
			tmp = curr->next;
			remove_node_lt(minishell->line, curr);
			curr = tmp;
			while (curr && curr->next && curr->next->val && *curr->next->val != opened_ch) // too much problem here
			{
				tmp = curr->next->next;
				ft_append(&curr->val, curr->next->val);
				remove_node_lt(minishell->line, curr->next);
				curr = tmp;
			}// check from here
			if (curr->next)
			{
				tmp = curr->next->next;
				printf("curr->next->val: %s\n", curr->next->val);
				_update_quote_info(&open, &opened_ch, curr->next);
				remove_node_lt(minishell->line, curr->next);
			}
			else
			{
				tmp = curr->next;
				printf("curr->val: %s\n", curr->val);
				_update_quote_info(&open, &opened_ch, curr);
				remove_node_lt(minishell->line, curr);
			}
			curr = tmp;
			// printf("the curr->val: %s\n", curr->val);
		}
		else
			curr = curr->next;
	}
}