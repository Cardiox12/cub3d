/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:34:34 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 01:34:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*concat;
	char			*begin;

	concat = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (concat == NULL)
		return (NULL);
	begin = concat;
	while (*s1)
		*concat++ = *s1++;
	while (*s2)
		*concat++ = *s2++;
	*concat = '\0';
	return (begin);
}