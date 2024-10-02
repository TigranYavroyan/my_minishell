/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:16 by tigran            #+#    #+#             */
/*   Updated: 2024/09/29 18:24:40 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int _count (char* input, char* delim) {
	int res;

	res = 0;
	while (input[res] != '\0' && !ft_strchr(delim, input[res]))
		++res;
	if (res == 0)
		return (1);
	return (res);
}

static void ft_split_delim(t_list_ptr line, char* delim, char* input) { // check later
	int		i;
	int		len;

	i = 0;
	while (input[i] != '\0') {
		len = _count(input + i, delim);
		push_back_move_lt(line, ft_substr(input + i, 0, len));
		i += len;
	}
	// print_lt(line);
}

void tokenize (t_minishell_ptr minishell, char* delim, char* input) {
	ft_split_delim(minishell->line, delim, input);
}