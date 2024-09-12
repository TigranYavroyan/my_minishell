/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:55 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/12 19:49:12 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <curses.h>
# include <bst.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <list.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_minishell	t_minishell;
typedef t_minishell* 		t_minishell_ptr;
typedef struct s_command	t_command;
typedef t_command*			t_command_ptr;

struct s_minishell {
	t_list_ptr	line;
	t_BST_ptr	env;
};

struct s_command {
    t_minishell_ptr minishell;
    char* name;
    t_list args;
    t_list options;
};

t_minishell_ptr init_minishell (char** env);
void clear_minishell (t_minishell_ptr* minishell);

// tokenizing
void tokenize (t_minishell_ptr minishell, char* delim, char* input);

// quotes
void ft_remove_quotes(t_list_ptr line);
bool ft_quotes_check(t_list_ptr line);

// helpers
bool is_quote(char ch);

#endif // MINISHELL_H
