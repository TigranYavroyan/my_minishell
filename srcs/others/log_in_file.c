/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_in_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:36:29 by tigran            #+#    #+#             */
/*   Updated: 2024/09/21 13:02:28 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void log_header_in_file ()
{
	int fd = open("log.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
	const char* line = "-----------------------------------------------------------------------\n\n";

	write(fd, line, ft_strlen(line));

}

void log_in_file (char* input)
{
	int fd = open("log.txt", O_RDWR | O_APPEND);

	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);

	close(fd);
}