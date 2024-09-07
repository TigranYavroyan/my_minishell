/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/07 14:09:28 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node	t_node;
typedef struct s_list	t_list;
typedef t_list			*t_list_ptr;

struct					s_node
{
	char				*val;
	t_node				*prev;
	t_node				*next;
};

struct					s_list
{
	t_node				*head;
	t_node				*tail;
	int					size;
};

bool	empty_lt(t_list_ptr list);

t_list_ptr	init_lt();

void	push_back_lt(t_list_ptr list, char *const str);

void	move_back_lt(t_list_ptr left, t_list_ptr right);

void	push_front_lt(t_list_ptr list, char *const str);

void	insert_node_lt(t_list_ptr list, char *str, t_node *node);

void	remove_if_lt(t_list_ptr list, char *val);

void	remove_index_node_lt(t_list_ptr list, int index);

void	remove_node_lt(t_list_ptr list, t_node *node);

void	remove_if_range_lt(t_list_ptr list, t_node *start,
			t_node *end, char *val);

void	pop_back_lt(t_list_ptr list);

void	pop_front_lt(t_list_ptr list);

void	clear_lt(t_list_ptr* list);

char	*at_lt(t_list_ptr list, int index);

bool	diff_lt(char *word, char *to_cmp);

t_list_ptr	copy_lt(t_list_ptr other);

t_list_ptr	copy_range_lt(t_node *node, t_node *end);

int		value_counter_lt(t_list_ptr list, char *src);

t_node	*find_word_lt(t_node *node, char *word);
void	free_node(t_node **node);
t_node	*find_word_range_lt(t_node *curr, t_node *end, char *word);
t_node	*find_word_if_lt(t_node *node, bool (*p)(char *));
int		find_index_lt(t_list_ptr list, t_node *to_find);

char	**list_to_matrix_lt(t_list_ptr list);

// helpers.c
void	print_lt(t_list_ptr list);
t_node	*make_node(char *str);

#endif // LIST_H
