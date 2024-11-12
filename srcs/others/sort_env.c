/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:31:46 by tyavroya          #+#    #+#             */
/*   Updated: 2024/11/12 17:51:54 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	_swap(char **left, char **right)
{
	char	*tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

static void	heapify(char **env, int i, int size)
{
	int	left;
	int	right;
	int	curr;

	left = 2 * i + 1;
	right = 2 * i + 2;
	curr = i;
	if (left < size && _greater(env[left], env[curr]))
		curr = left;
	if (right < size && _greater(env[right], env[curr]))
		curr = right;
	if (curr != i)
	{
		_swap(env + curr, env + i);
		heapify(env, curr, size);
	}
}

void	sort_env(char **env)
{
	int	size;
	int	i;

	size = 0;
	while (env[size])
		++size;
	i = size / 2;
	while (i >= 0)
	{
		heapify(env, i, size);
		--i;
	}
	i = size - 1;
	while (i >= 0)
	{
		_swap(env + i, env);
		heapify(env, 0, i);
		--i;
	}
}
