/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:19 by tigran            #+#    #+#             */
/*   Updated: 2024/09/14 21:10:17 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void __ft_minishell__ (t_minishell_ptr minishell, char* input) {
	minishell->commands = init_cmds(minishell);
    tokenize(minishell, "<>| \'\"()&", input);
    if (!ft_quotes_check(minishell->line))
        _err("Not all the quotes closed");
    ft_remove_spaces(minishell->line);
	ft_count_cmds(minishell);
	get_cmds(minishell);
    add_history(input);
}

static void ft_minishell (t_minishell_ptr minishell) {
    char* input;

    while (true)
    {
        input = readline("Minishell>$ ");
        __ft_minishell__(minishell, input);
        clear_lt(minishell->line);
		clear_cmds(minishell->commands);
		if (_equal(input, "exit"))
			break;
        free(input);
		free(minishell->commands);
    }
    free(input);
}

int main (int argc, char** argv, char** env)
{
    t_minishell_ptr minishell;

    if (argc != 1 && argv[0])
        _err("Too much arguments");
    minishell = init_minishell(env);
    ft_minishell(minishell);
    clear_minishell(&minishell);
	system("leaks minishell");
}