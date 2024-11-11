/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:28:46 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 00:20:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static void	_bst_to_matrix(t_treenode_ptr root, char **res, int *i);

char	**bst_to_matrix(t_bst_ptr tree)
{
	char	**res;
	int		i;

	res = (char **)wrapper_malloc(sizeof(char *) * (tree->size + 1));
	res[tree->size] = NULL;
	i = 0;
	_bst_to_matrix(tree->root, res, &i);
	return (res);
}

static void	_bst_to_matrix(t_treenode_ptr root, char **res, int *i)
{
	char	*row;

	if (!root)
		return ;
	_bst_to_matrix(root->left, res, i);
	row = ft_strdup(root->key);
	ft_append(&row, "=");
	ft_append(&row, root->value);
	res[*i] = row;
	row = NULL;
	++(*i);
	_bst_to_matrix(root->right, res, i);
}
