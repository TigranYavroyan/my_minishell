/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:23:51 by tigran            #+#    #+#             */
/*   Updated: 2024/10/10 20:08:53 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_out (char** output)
{
	int	i;

	if (!output || !(*output))
		return ;

	i = -1;
	while (output[++i + 1])
		printf("%s ", output[i]);
	printf("%s", output[i]);
}

void ft_echo(t_command_ptr command) // fix echo -nnnnnnnnnnnnnnn adsfads \case
{
	char		**output;
	t_node_ptr	s;

	output = NULL;
	move_back_lt(&command->options, command->args);
	if (!empty_lt(command->options) && _equal(command->options->head->val, "-n"))
	{
		s = command->options->head;
		while (s && _equal(s->val, "-n"))
			s = s->next;
		output = from_head_to_matrix_lt(s);
		print_out(output);
	}
	else
	{
		output = list_to_matrix_lt(command->options);
		print_out(output);
		printf("\n");
	}
	set_status_unsigned(VAL_CMD);
	remove_2d_str(output);
}