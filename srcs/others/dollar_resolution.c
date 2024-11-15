/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:22:15 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/15 14:48:48 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_value_type	_find_right_end(t_value_type begin);
static t_value_type	_till_dollar(t_value_type begin);
static void			_resolve(t_dollar_info_ptr df, t_value_type begin,
						t_minishell_ptr minishell);
static void			_final_res(t_value_type *curr, t_value_type begin,
						t_dollar_info_ptr df);

void	ft_dollar_resolution(t_minishell_ptr minishell, t_node_ptr curr,
		t_value_type begin, t_value_type *val)
{
	t_dollar_info	df;
	t_value_type	tmp_begin;

	// for e$SMTH hello case
	// check for $"" (???)
	tmp_begin = begin;
	if (ft_strlen(begin - 1) == 1)
		return ;
	df.res = NULL;
	df.end = NULL;
	if (is_single_quoted(minishell->quote_tracker, curr))
		return ;
	else
	{
		_resolve(&df, begin, minishell);
		while (*df.end != '\0')
		{
			begin = df.end + 1;
			_resolve(&df, begin, minishell);
		}
		_final_res(val, tmp_begin, &df);
	}
}

static void	_final_res(t_value_type *curr, t_value_type begin,
		t_dollar_info_ptr df)
{
	t_value_type	tmp;

	if (*curr == begin)
	{
		free(*curr);
		*curr = df->res;
	}
	else
	{
		tmp = ft_substr(*curr, 0, ft_strlen_range(*curr, begin - 1));
		free(*curr);
		*curr = tmp;
		ft_append(curr, df->res);
		free(df->res);
	}
}

static void	_resolve(t_dollar_info_ptr df, t_value_type begin,
		t_minishell_ptr minishell)
{
	t_value_type	val;

	if (df->end && *(df->end) == '$' && *(df->end + 1) == '\0')
	{
		ft_append(&df->res, "$");
		++df->end;
		return ;
	}
	df->end = _find_right_end(begin);
	if (*begin == '?')
	{
		df->resolved = ft_itoa(get_status());
		ft_append(&df->res, df->resolved);
		free(df->resolved);
	}
	else
	{
		df->resolved = get_bst_range(minishell->env, begin, df->end);
		ft_append(&df->res, df->resolved);
	}
	begin = df->end;
	df->end = _till_dollar(df->end);
	val = ft_substr(begin, 0, ft_strlen_range(begin, df->end));
	ft_append(&df->res, val);
	free(val);
}

static t_value_type	_find_right_end(t_value_type begin)
{
	if (!begin || (!ft_isalpha(*begin) && *begin != '_'))
		return (begin + 1);
	++begin;
	while (begin && *begin != '\0' && (ft_isalnum(*begin) || *begin == '_'))
		++begin;
	return (begin);
}

static t_value_type	_till_dollar(t_value_type begin)
{
	while (begin && *begin != '$' && *begin != '\0')
		++begin;
	return (begin);
}
