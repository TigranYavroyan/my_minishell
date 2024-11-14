/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:49:31 by tigran            #+#    #+#             */
/*   Updated: 2024/11/14 15:00:37 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

inline static bool	__parse(t_minishell_ptr minishell)
{
	if (!remove_quotes(minishell->line, minishell->quote_tracker))
		return (true);
	parse_dollar(minishell);
	merge_in_quotes(minishell->line, minishell->quote_tracker);
	remove_spaces(minishell->line, minishell->quote_tracker);
	return (false);
}

bool	syntax_check(t_minishell_ptr minishell)
{
	char	*err;

	if (__parse(minishell))
		return (true);
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
