/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:37:48 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/07 22:37:38 by tyavroya         ###   ########.fr       */
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
			_update_quote_info(&open, &opened_ch, curr);
			printf("the curr->val: %s\n", curr->val);
			remove_node_lt(minishell->line, curr);
		}
		curr = curr->next;
	}
}