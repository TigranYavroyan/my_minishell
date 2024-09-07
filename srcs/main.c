#include <minishell.h>

int main (int argc, char** argv, char** env) {

    if (argc != 1 && argv[0])
        _err("Too much arguments");

    t_minishell_ptr minishell;

    minishell = init_minishell(env);

    traverse_bst(minishell->env, INORDER, NULL);

    // while (!_equal(minishell->line->head, "exit")) {
        
    // }
    clear_minishell(&minishell);
}