/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:22:15 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/02 19:32:44 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// if in the name is symbol which is can't be the variable name , it is can't be deleted from node
void ft_dollar_resolution(t_minishell_ptr minishell, t_node_ptr curr, char opened_ch) // not complete
{
	t_value_type	val;
	t_value_type	tmp;

	tmp = curr->val;
	if (opened_ch == '\'')
		return ;
	else
	{
		val = get_bst(minishell->env, tmp + 1);
		free(curr->val);
		curr->val = ft_strdup(val);
	}
}