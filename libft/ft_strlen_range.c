/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:47:31 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/03 14:49:20 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlen_range (char* begin, char* end)
{
	int	count;

	count = 0;
	if (!begin || !end)
		return (0);
	while ((begin + count) != end)
		++count;
	return (count);
}