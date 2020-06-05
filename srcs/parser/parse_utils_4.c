/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:45:40 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:11:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	stack_free(t_stack **root)
{
	while (stack_height(*root) != 0)
		stack_pop(root);
}

void	string_array_free(char **strs, int size)
{
	int index;

	index = 0;
	while (index < size)
		free(strs[index++]);
	free(strs);
}

char	**string_array_copy(char **strs, int size)
{
	char	**copy;
	char	*tmp;
	int		index;

	copy = (char**)malloc(sizeof(char*) * (size + 1));
	if (copy == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		if ((tmp = ft_strdup(strs[index])) == NULL)
		{
			if (index != 0)
			{
				string_array_free(copy, index);
				free(copy);
			}
			free(copy);
			return (NULL);
		}
		copy[index] = tmp;
		index++;
	}
	copy[index] = NULL;
	return (copy);
}

int		is_empty_line(t_game *data)
{
	char *line;

	line = skip_spaces(data->map.line);
	if (*line != '\0')
		return (CODE_ERR_NON_EMPTY_LINE_AT_EOF);
	free(data->map.line);
	data->map.line = NULL;
	return (RET_NO_ERROR);
}
