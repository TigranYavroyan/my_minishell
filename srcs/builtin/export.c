/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:22 by tigran            #+#    #+#             */
/*   Updated: 2024/10/19 23:10:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_for_export_bst(t_key_type key, t_value_type value)
{
	printf("declare -x %s", key);
	if (value)
	{
		printf("=\"");
		if (*value)
			printf("%s", value);
		printf("\"");
	}
	printf("\n");
}

static void	_add_variable(t_minishell_ptr minishell, t_node_ptr curr,
		char *eq_sign)
{
	t_key_type		key;
	t_value_type	value;

	key = ft_substr(curr->val, 0, (eq_sign - curr->val));
	value = NULL;
	if (eq_sign)
		value = ft_strdup(eq_sign + 1);
	if (value)
	{
		insert_bst(minishell->env, key, value);
		insert_bst(minishell->export, key, value);
	}
	else
	{
		insert_bst(minishell->export, key, value);
	}
	free(key);
	free(value);
}

void	ft_export(t_command_ptr command)
{
	char		*eq_sign;
	t_node_ptr	curr;

	if (!empty_lt(command->options))
		__err_msg_full_prmt__("export: ", command->options->head->val,
			": invalid option", INV_OPTION);
	else if (!empty_lt(command->args))
	{
		curr = command->args->head;
		while (curr)
		{
			eq_sign = ft_strchr(curr->val, '=');
			if (!is_var_name(curr->val, eq_sign))
				__err_msg_full_prmt__("export: `", curr->val,
					"\': not a valid identifier", INV_ARG);
			else
				_add_variable(command->minishell, curr, eq_sign);
			curr = curr->next;
		}
	}
	else
		traverse_bst(command->minishell->export, INORDER, print_for_export_bst);
}
