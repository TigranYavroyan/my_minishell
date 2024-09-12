/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:19 by tigran            #+#    #+#             */
/*   Updated: 2024/09/12 19:56:40 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void __ft_minishell__ (t_minishell_ptr minishell, char* input) {
    tokenize(minishell, "<>| \'\"()&", input);
    if (!ft_quotes_check(minishell->line))
        _err("Not all the quotes closed");
    ft_remove_quotes(minishell->line);
    add_history(input);
}

static void ft_minishell (t_minishell_ptr minishell) {
    char* input;

    while (true)
    {
        input = readline("Minishell>$ ");
        __ft_minishell__(minishell, input);
        clear_lt(minishell->line);
        free(input);
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
}