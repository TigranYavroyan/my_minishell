/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:41:56 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/19 20:14:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_pwd(void)
{
	return (getcwd(NULL, 0));
}

char	*catch_home(t_command_ptr command)
{
	return (get_bst(command->minishell->env, "HOME"));
}

void	set_pwd(char *old_pwd, t_command_ptr command)
{
	char	*pwd;

	pwd = get_pwd();
	insert_bst(command->minishell->env, "OLDPWD", old_pwd);
	insert_bst(command->minishell->export, "OLDPWD", old_pwd);
	insert_bst(command->minishell->env, "PWD", pwd);
	insert_bst(command->minishell->export, "PWD", pwd);
	free(pwd);
}

bool	ft_chdir(char *path, t_command_ptr command)
{
	int	status;

	status = chdir(path);
	if (status == -1)
	{
		if (errno == ENOTDIR)
		{
			__err_msg_full_prmt__("cd: ", command->args->head->val,
				": Not a directory", INV_ARG);
		}
		else if (errno == EACCES)
		{
			__err_msg_full_prmt__("cd: ", command->args->head->val,
				": Permission denied", INV_ARG);
		}
		else if (errno == ENOENT)
		{
			__err_msg_full_prmt__("cd: ", command->args->head->val,
				": No such file or directory", INV_ARG);
		}
		return (false);
	}
	return (true);
}
