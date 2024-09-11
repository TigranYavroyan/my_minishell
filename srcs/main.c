#include <minishell.h>

static void __ft_minishell__ (t_minishell_ptr minishell, char* input) {
    tokenize(minishell, "<>| \'\"()&", input);
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