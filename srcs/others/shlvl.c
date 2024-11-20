/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:00:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/20 20:52:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	level_check(t_value_type value)
{
	int	level;

	level = ft_atoi(value);
	if (level < 0)
		level = 0;
	else if (level >= 0 && level <= 999)
		++level;
	else
		level = 1;
	return (level);
}

void	shlvl_process(t_minishell_ptr minishell)
{
	t_treenode_ptr	found;
	int				level;

	found = _find_bst(minishell->env->root, "SHLVL");
	if (found)
	{
		level = level_check(found->value);
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
