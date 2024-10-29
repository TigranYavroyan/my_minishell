#include <minishell.h>

static void shlvl_process (t_minishell_ptr minishell) {
	t_treenode_ptr	found;
	char			*val;
	int				level;

	found = _find_bst(minishell->env->root, "SHLVL");
	if (found)
	{
		val = found->value;
		level = ft_atoi(val);
		++level;
		val = ft_itoa(level);
		free(found->value);
		found->value = val;
	}
	else {
		insert_bst(minishell->export, "SHLVL", "1");
		insert_bst(minishell->env, "SHLVL", "1");
	}
}

t_minishell_ptr init_minishell (char** env) {
	t_minishell_ptr minishell;

	minishell = (t_minishell_ptr)wrapper_malloc(sizeof(t_minishell));
	minishell->line = init_lt();
	minishell->quote_tracker = init_set();
	sort_env(env); // env have to be not sorted, check after
	minishell->env = matrix_to_bst(env, '='); // matrix_to_bst_works only with sorted container
	insert_bst(minishell->env, "OLDPWD", NULL);
	minishell->export = copy_bst(minishell->env);
	shlvl_process(minishell);
	minishell->commands = NULL;
	minishell->descriptors = make_descriptors();

	return minishell;
}