/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:28:54 by tigran            #+#    #+#             */
/*   Updated: 2024/09/26 14:11:15 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool is_dir (char* name)
{
	// struct stat info;

	// if (stat(name, &info) == -1)
	// 	_err("chlpik"); // check later
	
	
	if (_equal(name, "."))
	{
		__err_msg_prmt__(".", ": filename argument required", INV_OPTION);
		return (true);
	}
	return (false);
}

bool is_num_str(const char* str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	if (str[i] == '-')
		++i;
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