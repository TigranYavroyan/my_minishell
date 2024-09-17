/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:08:30 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/17 20:27:12 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char**	get_path (t_minishell_ptr minishell)
{
	char**	res;
	char*	path;

	path = get_bst(minishell->env, "PWD");
	res = ft_split(path, ':');
	printf("%s\n", path);
	return (res);
}

bool	access_cmd(t_command_ptr command)
{
	char	**path;

	path = get_path(command->minishell);
	for (int i = 0; path[i]; ++i)
		printf("%s\n", path[i]);
	return (true);
}