/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:45:40 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/21 20:30:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	Stack_free(t_stack **root)
{
	while (Stack_height(*root) != 0)
		Stack_pop(root);
}

void 	String_array_free(char **strs, int size)
{
	int index;

	index = 0;
	while (index < size)
		free(strs[index++]);
}

char	**String_array_copy(char **strs, int size)
{
	char	**copy;
	char	*tmp;
	int 	index;

	copy = (char**)malloc(sizeof(char*) * (size + 1));
	if (copy == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		tmp = ft_strdup(strs[index]);
		if (tmp == NULL)
		{
			if (index != 0)
				String_array_free(copy, index);
			free(copy);
			return (NULL);
		}
		copy[index] = tmp;
		index++;
	}
	copy[index] = NULL;
	return (copy);
}