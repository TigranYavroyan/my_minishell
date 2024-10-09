/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:55 by tyavroya          #+#    #+#             */
/*   Updated: 2024/10/09 19:38:17 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <bst.h>
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <limits.h>
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

# define UNUSED __attribute__((unused))
# define DTOR __attribute__((destructor))
# define INV_OPTION 2
# define INV_ARG 1
# define VAL_CMD 0
# define CMD_NOT_FOUND 127
# define DIR_ERROR 126
# define EXIT_ERROR 255
# define SYNTAX_ERROR 258
# define LEAKS false

# define string __attribute__((cleanup(auto_free))) char *

typedef struct s_minishell		t_minishell;
typedef t_minishell				*t_minishell_ptr;
typedef struct s_command		t_command;
typedef t_command				*t_command_ptr;
typedef struct s_cmd_matrix		t_cmd_matrix;
typedef t_cmd_matrix			*t_cmd_matrix_ptr;
typedef enum e_direct			t_direct;
typedef struct s_descriptors	t_descriptors;
typedef t_descriptors			*t_descriptors_ptr;
typedef struct s_dollar_info	t_dollar_info;
typedef	t_dollar_info			*t_dollar_info_ptr;

enum							e_direct
{
	in = 0,
	out = 1,
	redirect_in = 2,
	redirect_out = 4,
	redirect_heredoc = 8
};

struct							s_dollar_info
{
	t_value_type	end;
	t_value_type	resolved;
	t_value_type	res;
};

struct							s_descriptors
{
	int							stdout;
	int							stdin;
	int							stderr;
};

struct							s_command
{
	t_minishell_ptr				minishell;
	char						*name;
	t_list_ptr					args;
	t_list_ptr					options;
};

struct							s_minishell
{
	t_list_ptr					line;
	t_bst_ptr					env;
	t_bst_ptr					export;
	t_cmd_matrix_ptr			commands;
	t_descriptors_ptr			descriptors;
};

struct							s_cmd_matrix
{
	t_minishell_ptr				minishell;
	t_command_ptr				*cmds;
	int							size;
};

t_minishell_ptr					init_minishell(char **env);
void							clear_minishell(t_minishell_ptr *minishell);

// tokenizing
void							tokenize(t_minishell_ptr minishell, char *delim,
									char *input);

// quotes_check
bool							ft_quotes_check(t_list_ptr line);

// symbol_resolution
void							ft_symbol_resolution(t_minishell_ptr minishell);
void							_update_quote_info(bool *open, char *opened_ch, t_node_ptr curr);

// dollar_resolution
void							ft_dollar_resolution(t_minishell_ptr minishell,
									t_node_ptr curr,
									t_value_type begin, char opened_ch);

// helpers
void							remove_2d_str(char **str);
void							ft_err_msg(char *msg);
void							__err_msg__(char *name, char *err, int val);
void							__err_msg_prmt__(char *name, char *err,
									int val);
void							auto_free(char **ptr);

// check_helpers
bool							is_num_str(const char *str);
bool							is_quote(char ch);
bool							is_dir(char *name);

// append
void							ft_append(char **left, char *right);

// check_builtin
bool							is_builtin(const char *val);

// cmds_count
void							ft_count_cmds(t_minishell_ptr minishell);

// cmds_utils
t_cmd_matrix_ptr				init_cmds(t_minishell_ptr minishell);
void							clear_cmds(t_cmd_matrix_ptr commands);
void							init_cmd(t_cmd_matrix_ptr cmds);

// get_cmds
void							get_cmds(t_minishell_ptr minishell);

// pipe_check
bool							pipe_check(t_list_ptr line);

// execute
void							execute(t_minishell_ptr minishell);

// exec_builtin
void							exec_builtin(t_command_ptr command);

// echo
void							ft_echo(t_command_ptr command);

// cd
void							ft_cd(t_command_ptr command);

// pwd
void							ft_pwd(t_command_ptr command);

// export
void							ft_export(t_command_ptr command);

// unset
void							ft_unset(t_command_ptr command);

// env
void							ft_env(t_command_ptr command);

// exit
void							ft_exit(t_command_ptr command);

// get_cmd_path
bool							access_cmd(t_command_ptr command);
bool							_exec_util(char *full_path,
									t_command_ptr command, bool is_btin,
									int *fds);

// sort_env
void							sort_env(char **env);

// is_var_name
bool							is_var_name(char *s, char *e);

// status
void							set_status_unsigned(int status);
void							set_status_signed(int status);
int								get_status(void);

// log_in_file
void							log_in_file(char *input);
void							log_header_in_file(void);

// descriptors
t_descriptors_ptr				make_descriptors(void);

// merge_quotes
void							ft_merge_quotes(t_minishell_ptr minishell);


#endif // MINISHELL_H
