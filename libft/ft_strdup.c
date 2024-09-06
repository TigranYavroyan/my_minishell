/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:41:44 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/06 19:09:01 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*tmp_dup;

	dup = (char *)wrapper_malloc(ft_strlen(src) + 1);
	tmp_dup = dup;
	while (src && *src)
	{
		*dup = *src;
		++dup;
		++src;
	}
	*dup = '\0';
	return (tmp_dup);
}
