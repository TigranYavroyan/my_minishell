/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:19 by tigran            #+#    #+#             */
/*   Updated: 2024/11/15 18:19:25 by healeksa         ###   ########.fr       */
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

	signal_handle();
	while (true)
	{
		input = readline("Minishell>$ ");
		minishell->commands = init_cmds(minishell);
		if (!input)
		{
			ft_putstr_fd("exit\n", 2);
			break ;
		}
		if (input[0] != '\0')
			add_history(input);
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
