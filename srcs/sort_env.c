/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:31:46 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/17 20:34:16 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void sort_env (char** env)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (env[size])
		++size;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j)
	}
}