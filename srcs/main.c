/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:19 by tigran            #+#    #+#             */
/*   Updated: 2024/10/02 13:55:42 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	__ft_minishell__(t_minishell_ptr minishell, char *input)
{
	minishell->commands = init_cmds(minishell);
	tokenize(minishell, "<>| \'\"()&", input);
	ft_remove_spaces(minishell->line);
	if (!ft_quotes_check(minishell->line))
	{
		__err_msg_prmt__(NULL, "Unclosed quotes", SYNTAX_ERROR);
		return ;
	}
	if (!pipe_check(minishell->line))
	{
		__err_msg_prmt__(NULL, "syntax error near unexpected token `|\'",
			SYNTAX_ERROR);
		return ;
	}
	ft_count_cmds(minishell);
	get_cmds(minishell);
	execute(minishell);
	add_history(input);
}

static void	ft_minishell(t_minishell_ptr minishell)
{
	char	*input;

	log_header_in_file();
	while (true)
	{
		input = readline("Minishell>$ ");
		if (!input) {
			printf("empty line: readline err\n");
			break;
		}
		log_in_file(input);
		__ft_minishell__(minishell, input);
		clear_lt(minishell->line);
		clear_cmds(minishell->commands);
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