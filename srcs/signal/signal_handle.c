/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:53:37 by healeksa          #+#    #+#             */
/*   Updated: 2024/11/18 21:33:49 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_signals(int sig);
void	restore_prompt(int sig);
void	ctrl_c(int sig);
void	back_slash(int sig);
void	sig_handler_hdoc(int sig);

void	run_signals(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, back_slash);
	}
	if (sig == 4)
	{
		signal(SIGINT, sig_handler_hdoc);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	restore_prompt(int sig)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

void	ctrl_c(int sig)
{
	write(1, "\n", 1);
	(void)sig;
}

void	back_slash(int sig)
{
	ft_putendl_fd("Quit: 3", 2);
	(void)sig;
}

void	sig_handler_hdoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	set_status_unsigned(1);
	// exit(1);
}
