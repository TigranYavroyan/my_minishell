/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:00:31 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/15 18:22:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	shlvl_process(t_minishell_ptr minishell)
{
	t_treenode_ptr	found;
	int				level;

	found = _find_bst(minishell->env->root, "SHLVL");
	if (found)
	{
		level = ft_atoi(found->value);
		if (level < 0)
			level = 0;
		else if (level >= 0 && level <= 999)
			++level;
		else
			level = 1;
		if (level == 1000)
		{
			free(found->value);
			found->value = ft_strdup("");
		}
		else
		{
			free(found->value);
			found->value = ft_itoa(level);
		}
	}
	else
	{
		insert_bst(minishell->export, "SHLVL", "1");
		insert_bst(minishell->env, "SHLVL", "1");
	}
}

t_minishell_ptr	init_minishell(char **env)
{
	t_minishell_ptr	minishell;

	minishell = (t_minishell_ptr)wrapper_malloc(sizeof(t_minishell));
	minishell->line = init_lt();
	minishell->quote_tracker = init_set();
	sort_env(env);
	minishell->env = matrix_to_bst(env, '=');
	remove_bst(minishell->env, "OLDPWD");
	minishell->export = copy_bst(minishell->env);
	insert_bst(minishell->export, "OLDPWD", NULL);
	shlvl_process(minishell);
	minishell->commands = NULL;
	minishell->descriptors = make_descriptors();
	return (minishell);
}
