#include <minishell.h>

t_minishell_ptr init_minishell (char** env) {
	t_minishell_ptr minishell;

	minishell = (t_minishell_ptr)wrapper_malloc(sizeof(t_minishell));
	minishell->line = init_lt();
	minishell->quote_tracker = init_set();
	sort_env(env); // env have to be not sorted, check after
	minishell->env = matrix_to_bst(env, '='); // matrix_to_bst_works only with sorted container
	minishell->export = copy_bst(minishell->env);
	minishell->commands = NULL;
	minishell->descriptors = make_descriptors();

	return minishell;
}