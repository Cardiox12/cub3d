/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 02:08:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/19 02:17:17 by bbellavi         ###   ########.fr       */
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