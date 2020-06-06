/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:32:29 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:27:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strndup(const char *s, size_t len)
{
	char *string;
	char *begin;

	string = malloc(len + 1);
	if (string == NULL)
		return (NULL);
	begin = string;
	while (len-- != 0 && *s)
		*string++ = *s++;
	*string = '\0';
	return (begin);
}
