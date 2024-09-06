/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:45:55 by tigpetro          #+#    #+#             */
/*   Updated: 2024/07/31 21:46:43 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*wrapper_malloc(int bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
		_err("Malloc error");
	return (res);
}
