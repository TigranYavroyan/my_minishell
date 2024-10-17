/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:37:48 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/17 20:32:22 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_merge_quotes(t_minishell_ptr minishell) // echo "a"'b' case doesn't work
{
	char		opened_ch;
	bool		open;
	t_node_ptr	curr;
	t_node_ptr	tmp;

	curr = minishell->line->head;
	open = false;
	opened_ch = 0;
	while (curr)
	{
		update_quote_info(&open, &opened_ch, curr);
		if (open)
		{
			tmp = curr->next;
			curr = remove_node_lt(minishell->line, curr); // check without tmp
			curr = tmp;
			if (*curr->val == opened_ch)
			{
				tmp = curr->next;
				update_quote_info(&open, &opened_ch, curr);
				remove_node_lt(minishell->line, curr);
				curr = tmp;
			}
			else {
				while (curr && curr->next && curr->next->val && *curr->next->val != opened_ch)
				{
					tmp = curr->next->next;
					ft_append(&curr->val, curr->next->val);
					remove_node_lt(minishell->line, curr->next);
				}
				tmp = curr->next->next;
				update_quote_info(&open, &opened_ch, curr->next);
				remove_node_lt(minishell->line, curr->next);
				curr = tmp;
			}
		}
		else
			curr = curr->next;
	}
}