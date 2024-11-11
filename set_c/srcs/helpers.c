/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:40:23 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 00:29:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

t_setnode_ptr	make_set_node(t_node_ptr key, t_quote_type q_type)
{
	t_setnode_ptr	node;

	node = (t_setnode_ptr)wrapper_malloc(sizeof(t_setnode));
	node->q_type = q_type;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_quote_type	get_quote_type(char ch)
{
	if (ch == '\"')
		return (DOUBLE_QUOTE);
	else if (ch == '\'')
		return (SINGLE_QUOTE);
	else
	{
		printf("char ch = (%c) - ", ch);
		_err(QUOTE_MSG);
	}
	return (0);
}

void	_free_node_set(t_setnode_ptr *root)
{
	free(*root);
	*root = NULL;
}
