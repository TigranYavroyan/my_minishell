/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:23:51 by tigran            #+#    #+#             */
/*   Updated: 2024/11/16 20:03:21 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_out(char **output)
{
	int	i;

	if (!output && !(*output))
		return ;
	i = -1;
	while (output[++i + 1])
	{
		ft_putstr_fd(output[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd(output[i], 1);
}

static void	_check_flag_util(t_node_ptr tmp, int *i)
{
	while (tmp->val[*i])
	{
		if (tmp->val[*i] == 'n')
		{
			++(*i);
			continue ;
		}
		else
			break ;
	}
}

static t_node_ptr	check_flag(t_command_ptr command, bool *flag)
{
	t_node_ptr	tmp;
	int			i;

	tmp = command->options->head;
	while (tmp)
	{
		i = 0;
		if (tmp->val[i] == '-')
			++i;
		_check_flag_util(tmp, &i);
		if (tmp->val[i] != '\0' || i <= 1)
			return (tmp);
		if (i > 1)
			*flag = true;
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_echo(t_command_ptr command)
{
	char		**output;
	t_node_ptr	s;
	bool		flag;

	output = NULL;
	flag = false;
	move_back_lt(&command->options, command->args);
	s = check_flag(command, &flag);
	output = from_head_to_matrix_lt(s);
	print_out(output);
	if (!flag)
		printf("\n");
	set_status_unsigned(VAL_CMD);
	remove_2d_str(output);
}
