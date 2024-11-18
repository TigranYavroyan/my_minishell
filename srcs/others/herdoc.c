/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:20:42 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/18 21:34:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	heredoc_handle(t_command_ptr command)
{
	char			*line;
	int				fd;
	t_value_type	begin;

	fd = command->descriptors->stdin;
	run_signals(4);
	while (1)
	{
		line = readline("> ");
		if (!line || _equal(line, command->delim) || get_status() == 1)
			break ;
		if (!command->is_delim_quoted)
		{
			begin = ft_strchr(line, '$');
			if (begin)
				ft_dollar_resolution(command->minishell, NULL, begin + 1,
					&line);
		}
		ft_putendl_fd(line, fd);
		auto_free(&line);
	}
	auto_free(&line);
	close(fd);
	// clear_minishell(&(command->minishell));
	fd = open(HEREDOC_FILE, O_RDONLY, FILE_PERM);
	dup2(fd, STDIN_FILENO);
	// exit(EXIT_SUCCESS);
	return (false);
}
