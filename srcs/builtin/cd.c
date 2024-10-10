/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:02 by tigran            #+#    #+#             */
/*   Updated: 2024/10/10 20:46:32 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	old_pwd(t_command_ptr command)
{
	char	*pwd;

	pwd = get_bst(command->minishell->env, "OLDPWD");
	// if (!pwd)
	// insert_bst(command->minishell->env, "OLDPWD", );
}

static char	*catch_home(t_command_ptr command)
{
	char	*home;

	home = get_bst(command->minishell->env, "HOME");
	return (home);
}

void	ft_cd(t_command_ptr command)
{
	char	*path;
	int		status;
	char	*__err;

	if (!empty_lt(command->options))
	{
		printf("minishell: cd: %c%c: invalid option\n",
			command->options->head->val[0], command->options->head->val[1]);
		return ;
	}
	if (empty_lt(command->args))
	{
		path = catch_home(command);
		if (!path)
		{
			__err_msg_prmt__("cd: ", "HOME not set", 1);
			return ;
		}
	}
	else
		path = command->args->head->val;
	// old_pwd(command);
	status = chdir(path);
	if (status == -1)
	{
		if (errno == ENOTDIR)
		{
			__err = ft_strdup(command->args->head->val);
			ft_append(&__err, " : Not a directory");
			__err_msg_prmt__("cd: ", __err, INV_ARG);
			auto_free(&__err);
		}
		else if (errno == EACCES)
		{
			__err = ft_strdup(command->options->head->val);
			ft_append(&__err, " : Permission denied");
			__err_msg_prmt__("cd: ", __err, INV_ARG); /// poxenq pti
			auto_free(&__err);
		}
	}
}
