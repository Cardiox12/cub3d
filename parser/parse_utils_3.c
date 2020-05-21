/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 06:27:08 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/21 07:09:26 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_stack	*Stack_new_node(t_vec pos)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->pos = pos;
	return (node);
}

t_stack *Stack_push(t_stack **root, t_vec pos)
{
	t_stack *node;

	if ((node = Stack_new_node(pos)) == NULL)
		return (NULL);
	node->next = *root;
	*root = node;
	return (node);
}

t_vec	Stack_pop(t_stack **root)
{
	t_stack *old;
	t_vec	popped;

	popped = (t_vec){INT_MIN, INT_MIN};
	if (*root == NULL)
		return (popped);
	old = *root;
	*root = (*root)->next;
	popped = old->pos;
	free(old);
	return (popped);
}

t_vec	Stack_peek(t_stack *root)
{
	if (root == NULL)
		return ((t_vec){INT_MIN, INT_MIN});
	return (root->pos);
}

int 	Stack_height(t_stack *root)
{
	int height;

	height = 0;
	while (root != NULL)
	{
		root = root->next;
		height++;
	}
	return (height);
}