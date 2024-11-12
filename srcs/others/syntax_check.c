/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:49:31 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 17:49:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

inline static void	__parse(t_minishell_ptr minishell)
{
	remove_quotes(minishell->line, minishell->quote_tracker);
	parse_dollar(minishell);
	merge_in_quotes(minishell->line, minishell->quote_tracker);
	remove_spaces(minishell->line, minishell->quote_tracker);
}

bool	syntax_check(t_minishell_ptr minishell)
{
	char	*err;

	if (!ft_quotes_check(minishell->line))
	{
		__err_msg_prmt__(NULL, "Unclosed quotes", SYNTAX_ERROR);
		return (true);
	}
	__parse(minishell);
	if (!pipe_check(minishell->line, minishell->quote_tracker))
	{
		__err_msg_prmt__(NULL, "syntax error near unexpected token `|\'",
			SYNTAX_ERROR);
		return (true);
	}
	err = redir_check(minishell->line, minishell->quote_tracker);
	if (err)
	{
		__err_msg_full_prmt__("syntax error near unexpected token `", err, "\'",
			SYNTAX_ERROR);
		return (true);
	}
	return (false);
}
