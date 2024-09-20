/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_in_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:36:29 by tigran            #+#    #+#             */
/*   Updated: 2024/09/20 21:53:16 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void log_header_in_file ()
{
	int fd = open("log.txt", O_CREAT | O_RDWR | O_APPEND);
	const char* line = "-----------------------------------------------------------------------\n\n";

	write(fd, line, ft_strlen(line));

}

void log_in_file (char* input)
{
	int fd = open("log.txt", O_CREAT | O_RDWR | O_APPEND);

	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);

	close(fd);
}