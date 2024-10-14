/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:41:56 by healeksa          #+#    #+#             */
/*   Updated: 2024/10/12 20:54:00 by healeksa         ###   ########.fr       */
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
	insert_bst(command->minishell->env, "PWD", pwd);
	free(pwd);
}

bool	ft_chdir(char *path, t_command_ptr command)
{
	int		status;
	char	*__err;

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
			__err = ft_strdup(command->args->head->val);
			ft_append(&__err, " : Permission denied");
			__err_msg_prmt__("cd: ", __err, INV_ARG);
			auto_free(&__err);
		}
		else if (errno == ENOENT)
		{
			__err = ft_strdup(command->args->head->val);
			ft_append(&__err, " : No such file or directory");
			__err_msg_prmt__("cd: ", __err, INV_ARG); /// poxenq pti
			auto_free(&__err);
		}
		return (false);
	}
	return (true);
}
