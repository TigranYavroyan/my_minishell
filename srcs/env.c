/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:17:34 by tigran            #+#    #+#             */
/*   Updated: 2024/09/17 18:06:51 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env (t_command_ptr command)
{
	if (!empty_lt(command->options) || !empty_lt(command->args))
		return ;
	traverse_bst(command->minishell->env, INORDER, NULL);
}