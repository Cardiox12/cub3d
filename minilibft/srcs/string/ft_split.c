/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:53:11 by tony              #+#    #+#             */
/*   Updated: 2020/01/30 00:18:29 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_count_substr(const char *s, char c)
{
	size_t counter;

	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (counter);
}

static size_t	ft_strlen_to_sep(const char *s, char c)
{
	const char *final_s = s;

	while (*s && *s != c)
		s++;
	return (s - final_s);
}

static char		**ft_alloc_2d_array(size_t size)
{
	char **strings;

	strings = malloc(sizeof(char*) * size);
	if (strings == NULL)
		return (NULL);
	return (strings);
}

char			**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	index;

	index = 0;
	strings = ft_alloc_2d_array(ft_count_substr(s, c) + 1);
	if (strings == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			strings[index] = ft_strndup(s, ft_strlen_to_sep(s, c));
			if (strings == NULL)
				return (NULL);
			while (*s && *s != c)
				s++;
			index++;
		}
		else
			s++;
	}
	strings[index] = NULL;
	return (strings);
}