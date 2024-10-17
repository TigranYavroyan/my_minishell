/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:17:34 by tigran            #+#    #+#             */
/*   Updated: 2024/10/17 16:38:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(t_command_ptr command)
{
	if (!empty_lt(command->options))
		__err_msg_full__("env: ", "illegal option: ",
			command->options->head->val, CMD_NOT_FOUND);
	else if (!empty_lt(command->args))
		__err_msg_full__("env: ", command->args->head->val,
			": No such file or directory", INV_ARG);
	else
		traverse_bst(command->minishell->env, INORDER, NULL);
}
