/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:19 by tigran            #+#    #+#             */
/*   Updated: 2024/11/02 17:44:39 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	__ft_minishell__(t_minishell_ptr minishell, char *input)
{
	tokenize(minishell, "<>| \'\"()&", input);
	if (!ft_quotes_check(minishell->line))
	{
		__err_msg_prmt__(NULL, "Unclosed quotes", SYNTAX_ERROR);
		return ;
	}
	remove_quotes(minishell->line, minishell->quote_tracker);
	parse_dollar(minishell);
	merge_in_quotes(minishell->line, minishell->quote_tracker);
	remove_spaces(minishell->line, minishell->quote_tracker);
	if (!pipe_check(minishell->line, minishell->quote_tracker))
	{
		__err_msg_prmt__(NULL, "syntax error near unexpected token `|\'",
			SYNTAX_ERROR);
		return ;
	}
	if (!redir_check(minishell->line, minishell->quote_tracker))
	{
		// exit status must be 258
		__err_msg__("syntax error near unexpected token `newline\'", NULL, INV_OPTION);
		return ;
	}
	ft_count_cmds(minishell);
	get_cmds(minishell);
	execute(minishell);
}

static void	ft_minishell(t_minishell_ptr minishell)
{
	char	*input;

	log_header_in_file();
	signal_handle();
	while (true)
	{
		input = readline("Minishell>$ ");
		minishell->commands = init_cmds(minishell);
		if (!input)
			break ;
		if (input[0] != '\0')
			add_history(input);
		log_in_file(input);
		__ft_minishell__(minishell, input);
		clear_lt(minishell->line);
		clear_cmds(minishell->commands);
		clear_set(minishell->quote_tracker);
		free(minishell->commands);
		free(input);
	}
	free(input);
}

int	main(int argc, char **argv, char **env)
{
	t_minishell_ptr	minishell;

	if (argc != 1 && argv[0])
		_err("Too much arguments");
	minishell = init_minishell(env);
	ft_minishell(minishell);
	clear_minishell(&minishell);
}

#if LEAKS == true

void DTOR	___err___(void)
{
	system("leaks minishell");
}

#endif
