/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:28:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/08/21 23:03:31 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_str_ends_with(char *haystack, char *needle)
{
	return (!ft_strncmp(haystack + ft_strlen(haystack) - ft_strlen(needle),
			needle, ft_strlen(needle)));
}
