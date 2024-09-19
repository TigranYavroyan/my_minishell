/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:39:32 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/19 15:39:45 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_append(char **left, char *right)
{
	int l;
	int r;
	int i;
	char *tmp;

	if ((!left || !(*left)) && !right)
		return ;
	l = ft_strlen(*left);
	r = ft_strlen(right);
	tmp = wrapper_malloc(l + r + 1);
	tmp[l + r] = '\0';
	i = -1;
	while (++i < l)
		tmp[i] = (*left)[i];

	i = -1;
	while (++i < r)
		tmp[l + i] = right[i];
	free(*left);
	*left = tmp;
}