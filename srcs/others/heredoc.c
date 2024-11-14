/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:54:59 by tigran            #+#    #+#             */
/*   Updated: 2024/11/14 17:56:59 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lol(void)
{
}

void	child_heredoc(t_command_ptr command)
{
	char			*line;
	int				fd;
	t_value_type	begin;

	fd = command->descriptors->stdin;
	signal(SIGINT, signal_heredoc);
	while (1)
	{
		line = readline("> ");
		if (!line || _equal(line, command->delim))
			break ;
		if (!command->is_delim_quoted)
		{
			begin = ft_strchr(line, '$');
			if (begin)
				ft_dollar_resolution(command->minishell, NULL, begin + 1, &line);
		}
		ft_putendl_fd(line, fd);
		auto_free(&line);
	}
	auto_free(&line);
	close(fd);
	clear_minishell(&(command->minishell));
	exit(EXIT_SUCCESS);
}

bool	parrent_heredoc(t_command_ptr command)
{
	int	fd;
	int	status;

	close(command->descriptors->stdin);
	signal(SIGINT, SIG_IGN);
	wait(&status);
	fd = open(HEREDOC_FILE, O_RDONLY, FILE_PERM);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status == EXIT_FAILURE)
		{
			close(fd);
			signal_handle();
			return (false);
		}
		else
			dup2(fd, STDIN_FILENO);
	}
	signal_handle();
	return (true);
}

bool	heredoc_handle(t_command_ptr command)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		__err_msg_prmt__("fork", HEREDOC_ERR_MSG, FORK_ERROR);
	else if (pid == 0)
		child_heredoc(command);
	else
		return (parrent_heredoc(command));
	return (false);
}
