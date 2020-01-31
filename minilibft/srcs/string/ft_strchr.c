/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:44:06 by toto              #+#    #+#             */
/*   Updated: 2020/01/31 00:35:11 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	char char_c;

	char_c = c;
	while (*s)
	{
		if (*s == char_c)
			return ((char*)s);
		s++;
	}
	return ((*s == char_c) ? (char*)s : NULL);
}
