/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:54:59 by tigran            #+#    #+#             */
/*   Updated: 2024/11/12 18:05:06 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lol(void)
{
}

void	child_heredoc(t_command_ptr command)
{
	char	*line;
	int		fd;

	fd = command->descriptors->stdin;
	signal(SIGINT, signal_heredoc);
	while (1)
	{
		line = readline("> ");
		if (!line || _equal(line, command->delim))
			break ;
		if (command->is_delim_quoted)
			lol(); // var resolution
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
		ft_err_msg("fork: Resource temporarily unavailable");
	else if (pid == 0)
		child_heredoc(command);
	else
		return (parrent_heredoc(command));
	return (false);
}
