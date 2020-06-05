/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 02:08:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:08:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*skip_spaces(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && ft_isspace(*s))
		s++;
	return ((char*)s);
}

char	*skip_digits(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && ft_isdigit(*s))
		s++;
	return ((char*)s);
}

char	*skip_char(const char *s, unsigned char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s == c)
		s++;
	return ((char*)s);
}

int		has_valid_ext(const char *path)
{
	const size_t len = ft_strlen(path);
	const size_t ext_len = ft_strlen(MAP_EXT);

	if (len < 5)
		return (FALSE);
	if (ft_strncmp(&path[len - ext_len], MAP_EXT, ext_len) != 0)
		return (FALSE);
	return (TRUE);
}
