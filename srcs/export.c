/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:24:22 by tigran            #+#    #+#             */
/*   Updated: 2024/10/09 19:54:29 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void print_for_export_bst (t_key_type key, t_value_type value);
static void _add_variable (t_minishell_ptr minishell, t_node_ptr curr, char* eq_sign);

void	ft_export (t_command_ptr command)
{
	char		*eq_sign;
	char		*err;
	t_node_ptr	curr;

	err = ft_strdup("export: ");
	if (!empty_lt(command->options))
		printf("minishell: export: %s: invalid option\n", command->options->head->val);
	else if (!empty_lt(command->args))
	{
		curr = command->args->head;
		while (curr)
		{
			eq_sign = ft_strchr(curr->val, '=');
			if (!is_var_name(curr->val, eq_sign))
				printf("minishell: export: `%s': not a valid identifier\n", curr->val);
			else
				_add_variable(command->minishell, curr, eq_sign);
			curr = curr->next;
		}
	}
	else
		traverse_bst(command->minishell->export, INORDER, print_for_export_bst);
	free(err);
}

static void print_for_export_bst (t_key_type key, t_value_type value) {
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

static void _add_variable (t_minishell_ptr minishell, t_node_ptr curr, char* eq_sign)
{
	t_key_type	key;
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
