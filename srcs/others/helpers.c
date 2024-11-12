/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:43:10 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 18:01:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_2d_str(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i] != NULL)
		free(str[i]);
	free(str);
}

void	auto_free(char **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
