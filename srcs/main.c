/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:19 by tigran            #+#    #+#             */
/*   Updated: 2024/11/11 09:13:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	__ft_minishell__(t_minishell_ptr minishell, char *input)
{
	tokenize(minishell, "<>| \'\"()&", input);
	if (syntax_check(minishell))
		return ;
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
	// printf("getpid(): %d\n", getpid());
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
