/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_var_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:26:22 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/21 17:26:25 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_var_name (char* s, char* e)
{
	if (!s)
		return (false);
	if (!ft_isalpha(*s) && *s != '_')
		return (false);
	if (!e)
		e = s + ft_strlen(s);
	++s;
	while (s && s != e)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (false);
		++s;
	}
	return (true);
}