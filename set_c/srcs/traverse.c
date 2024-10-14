/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:50:05 by tigran            #+#    #+#             */
/*   Updated: 2024/10/14 20:25:08 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set.h>

static void	traverse_pre(t_setnode_ptr root, t_visitor_set fptr);
static void	traverse_in(t_setnode_ptr root, t_visitor_set fptr);
static void	traverse_post(t_setnode_ptr root, t_visitor_set fptr);
static void	print_for_traverse_bst(t_key_type key);

void	traverse_set(t_set_ptr tree, t_travers_type travers_type,
		t_visitor_set fptr)
{
	if (fptr == NULL)
		fptr = print_for_traverse_bst;
	if (travers_type == PREORDER)
		traverse_pre(tree->root, fptr);
	else if (travers_type == INORDER)
		traverse_in(tree->root, fptr);
	else if (travers_type == POSTORDER)
		traverse_post(tree->root, fptr);
	else
		_err("Invalid travers_type for traverse");
}

static void	traverse_pre(t_setnode_ptr root, t_visitor_set fptr)
{
	if (!root)
		return ;
	fptr(root->key);
	traverse_pre(root->left, fptr);
	traverse_pre(root->right, fptr);
}

static void	traverse_in(t_setnode_ptr root, t_visitor_set fptr)
{
	if (!root)
		return ;
	traverse_in(root->left, fptr);
	fptr(root->key);
	traverse_in(root->right, fptr);
}

static void	traverse_post(t_setnode_ptr root, t_visitor_set fptr)
{
	if (!root)
		return ;
	traverse_post(root->left, fptr);
	traverse_post(root->right, fptr);
	fptr(root->key);
}

static void	print_for_traverse_bst(t_key_type key)
{
	printf("%p", key);
	if (key->val)
		printf(": %s", key->val);
	printf("\n");
}