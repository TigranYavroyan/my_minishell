/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:13:30 by tigran            #+#    #+#             */
/*   Updated: 2024/10/09 22:10:24 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_builtin(const char *val)
{
	if (_equal(val, "echo"))
		return (true);
	if (_equal(val, "cd"))
		return (true);
	if (_equal(val, "pwd"))
		return (true);
	if (_equal(val, "export"))
		return (true);
	if (_equal(val, "unset"))
		return (true);
	if (_equal(val, "env"))
		return (true);
	if (_equal(val, "exit"))
		return (true);
	return (false);
}
