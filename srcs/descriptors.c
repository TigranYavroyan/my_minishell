/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:01:36 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/29 20:44:50 by tyavroya         ###   ########.fr       */
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
