/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:39 by tigran            #+#    #+#             */
/*   Updated: 2024/09/29 15:31:19 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

t_value_type	get_bst(t_bst_ptr bst, const t_key_type key)
{
	t_treenode_ptr	to_find;

	to_find = _find_bst(bst->root, key);
	if (to_find == NULL)
		return (NULL);
	return (to_find->value);
}
