/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:54:58 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/27 12:08:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*lst_create(void *ptr)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->ptr = ptr;
	return (node);
}

t_list	*lst_add(t_list **origin, void *ptr)
{
	t_list *first;
	t_list *node;

	first = *origin;
	if ((node = lst_create(ptr)) == NULL)
		return (NULL);
	if (first == NULL)
		*origin = node;
	else
	{
		while (first->next != NULL)
			first = first->next;
		first->next = node;
	}
	return (node);
}