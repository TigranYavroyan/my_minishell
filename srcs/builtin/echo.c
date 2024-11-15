/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:23:51 by tigran            #+#    #+#             */
/*   Updated: 2024/11/10 19:36:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_out(char **output)
{
	int	i;

	if (!output || !(*output))
		return ;
	i = -1;
	while (output[++i + 1])
		printf("%s ", output[i]);
	printf("%s", output[i]);
}

static t_node_ptr	check_flag(t_command_ptr command, bool *flag)
{
	t_node_ptr	tmp;
	int			i;

	tmp = command->options->head;
	while (tmp)
	{
		i = -1;
		while (tmp->val[++i])
		{
			if (i == 0 && tmp->val[i] == '-')
				continue ;
			else if (i != 0 && tmp->val[i] == 'n')
				continue ;
			else
				break ;
		}
		if (tmp->val[i] != '\0')
			return (tmp);
		if (i > 1)
			*flag = 1;
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
	flag = 0;
	move_back_lt(&command->options, command->args);
	s = check_flag(command, &flag);
	if (!s)
		return ;
	output = from_head_to_matrix_lt(s);
	print_out(output);
	if (!flag)
		printf("\n");
	set_status_unsigned(VAL_CMD);
	remove_2d_str(output);
}
