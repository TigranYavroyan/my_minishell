/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:22:15 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/03 19:44:19 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_value_type	_find_right_end(t_value_type begin);
static t_value_type _till_dollar(t_value_type begin);

static UNUSED void print_range (char* begin, char* end)
{
	printf("print_range: ");
	while (begin != end)
	{
		write(1, begin, 1);
		++begin;
	}
	write(1, "\n", 1);
}

void	ft_dollar_resolution(t_minishell_ptr minishell, t_node_ptr curr,
		t_value_type begin, char opened_ch) // not complete
{
	t_value_type	end;
	t_value_type	resolved;
	t_value_type	remainder;
	t_value_type	res;

	res = NULL;
	if (opened_ch == '\'')
		return ;
	else // leaks here
	{
		end = _find_right_end(begin);
		resolved = get_bst_range(minishell->env, begin, end);
		remainder = ft_substr(end, 0, ft_strlen(end));
		ft_append(&res, resolved);
		begin = end;
		end = _till_dollar(end);
		// printf("begin: %s\n", begin);
		// printf("end: %s\n", end);
		ft_append(&res, ft_substr(begin, 0, ft_strlen_range(begin, end)));
		// printf("begin: %s\n", begin);
		// printf("end: %s\n", end);
		while (*end != '\0')
		{
			begin = end + 1;
			end = _find_right_end(begin);
			// printf("begin: %s\n", begin);
			// printf("end: %s\n", end);
			// print_range(begin, end);
			resolved = get_bst_range(minishell->env, begin, end);
			remainder = ft_substr(end, 0, ft_strlen(end));
			ft_append(&res, resolved);
			begin = end;
			end = _till_dollar(end);
			// print_range(begin, end);
			ft_append(&res, ft_substr(begin, 0, ft_strlen_range(begin, end)));
		}
		free(curr->val);
		curr->val = res;
	}
}

static t_value_type	_find_right_end(t_value_type begin)
{
	if (!begin || (!ft_isalpha(*begin) && *begin != '_'))
		return (begin + 1);
	++begin;
	while (begin && *begin != '\0' && ft_isalnum(*begin))
		++begin;
	return (begin);
}

static t_value_type _till_dollar(t_value_type begin)
{
	while (begin && *begin != '$' && *begin != '\0')
		++begin;
	return (begin);
}