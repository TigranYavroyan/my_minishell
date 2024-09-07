#include <minishell.h>

void clear_minishell(t_minishell_ptr* minishell)
{
	clear_lt(&(*minishell)->line);
	clear_bst(&(*minishell)->env);
	free(*minishell);
	*minishell = NULL;
}