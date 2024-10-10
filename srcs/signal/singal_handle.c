/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:53:37 by healeksa          #+#    #+#             */
/*   Updated: 2024/10/10 11:53:40 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_quit(int sig)
{
	(void)sig;
	rl_redisplay();
}

void	sig_int(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handle(void)
{
	signal(SIGQUIT, sig_quit);
	signal(SIGINT, sig_int);
}
