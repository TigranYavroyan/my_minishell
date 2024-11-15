/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:00:31 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/15 20:22:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_minishell_ptr	init_minishell(char **env)
{
	t_minishell_ptr	minishell;

	minishell = (t_minishell_ptr)wrapper_malloc(sizeof(t_minishell));
	minishell->line = init_lt();
	minishell->quote_tracker = init_set();
	sort_env(env);
	minishell->env = matrix_to_bst(env, '=');
	remove_bst(minishell->env, "OLDPWD");
	shlvl_process(minishell);
	minishell->export = copy_bst(minishell->env);
	insert_bst(minishell->export, "OLDPWD", NULL);
	minishell->commands = NULL;
	minishell->descriptors = make_descriptors();
	return (minishell);
}
