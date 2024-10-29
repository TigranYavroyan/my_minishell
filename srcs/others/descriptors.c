/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:01:36 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/29 19:05:44 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_descriptors_ptr	make_descriptors(void)
{
	t_descriptors_ptr	dskt;

	dskt = wrapper_malloc(sizeof(t_descriptors));
	dskt->stdin = dup(STDIN_FILENO);
	dskt->stdout = dup(STDOUT_FILENO);
	dskt->stderr = dup(STDERR_FILENO);
	return dskt;
}
