// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   heredoc.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/04 20:54:59 by tigran            #+#    #+#             */
// /*   Updated: 2024/11/18 21:17:54 by healeksa         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <minishell.h>

// void	child_heredoc(t_command_ptr command)
// {
// 	char			*line;
// 	int				fd;
// 	t_value_type	begin;

// 	fd = command->descriptors->stdin;
// 	while (1)
// 	{
// 		run_signals(4);
// 		line = readline("> ");
// 		if (!line || _equal(line, command->delim))
// 		{
// 			run_signals(4);
// 			break ;
// 		}
// 		if (!command->is_delim_quoted)
// 		{
// 			begin = ft_strchr(line, '$');
// 			if (begin)
// 				ft_dollar_resolution(command->minishell, NULL, begin + 1,
// 					&line);
// 		}
// 		ft_putendl_fd(line, fd);
// 		auto_free(&line);
// 	}
// 	auto_free(&line);
// 	close(fd);
// 	clear_minishell(&(command->minishell));
// 	exit(EXIT_SUCCESS);
// }

// bool	parrent_heredoc(t_command_ptr command)
// {
// 	int	fd;
// 	int	status;

// 	close(command->descriptors->stdin);
// 	wait(&status);
// 	fd = open(HEREDOC_FILE, O_RDONLY, FILE_PERM);
// 	if (WIFEXITED(status))
// 	{
// 		status = WEXITSTATUS(status);
// 		if (status == EXIT_FAILURE)
// 		{
// 			close(fd);
// 			// printf("!!!!!!!!!!!!!!!!\n");
// 			run_signals(1);
// 			return (false);
// 		}
// 		else
// 			dup2(fd, STDIN_FILENO);
// 	}
// 	run_signals(1);
// 	return (true);
// }

// bool	heredoc_handle(t_command_ptr command)
// {
// 	pid_t	pid;

// 	run_signals(2);
// 	pid = fork();
// 	if (pid < 0)
// 		__err_msg_prmt__("fork", HEREDOC_ERR_MSG, FORK_ERROR);
// 	else if (pid == 0)
// 		child_heredoc(command);
// 	else
// 		return (parrent_heredoc(command));
// 	run_signals(1);
// 	return (false);
// }
