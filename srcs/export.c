/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:22 by tigran            #+#    #+#             */
/*   Updated: 2024/09/20 21:00:27 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void print_for_export_bst (key_type key, value_type value) {
    printf("declare -x %s=\"%s\"\n", key, value);
}

void	ft_export (t_command_ptr command)
{
	// if (!empty_lt(command->options))
	if (empty_lt(command->options) && empty_lt(command->args))
	{
		traverse_bst(command->minishell->export, INORDER, print_for_export_bst);
	}
}