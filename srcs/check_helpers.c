/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:28:54 by tigran            #+#    #+#             */
/*   Updated: 2024/09/24 18:22:59 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool is_num_str(const char* str, int* sign)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	*sign = 1;
	if (str[i] == '-')
	{
		++i;
		*sign = -1;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		++i;
	}
	return (true);
}

bool is_quote(char ch)
{
	return (ch == '\'' || ch == '\"');
}