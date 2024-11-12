/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:29 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 11:57:32 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_env_pwd(t_command_ptr command)
{
	char	*curr_path;

	curr_path = get_bst(command->minishell->env, "PWD");
	if (curr_path && curr_path[0] != '\0')
		return (curr_path);
	return (NULL);
}

static void	cwd(void)
{
	char	cwd_path[PATH_MAX];

	if (getcwd(cwd_path, sizeof(cwd_path)) != NULL)
		printf("%s\n", cwd_path);
	else
		perror("getcwd() error");
}

void	ft_pwd(t_command_ptr command)
{
	char	*cur;

	if (!empty_lt(command->options))
		return (__err_msg_full_prmt__("pwd: ", command->options->head->val,
				": invalid option", INV_ARG));
	cur = get_env_pwd(command);
	if (cur)
		printf("%s\n", cur);
	else
		cwd();
}
