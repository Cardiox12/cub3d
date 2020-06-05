/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:04:34 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/31 01:04:23 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	ft_isinset(const char *set, int c)
{
	unsigned char uchar;

	uchar = (unsigned char)c;
	while (*set)
	{
		if (uchar == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	const size_t	end = ft_strlen(s);
	int				left;
	int				right;
	int				size;
	char			*new;

	left = 0;
	right = end;
	while (ft_isinset(set, s[left]) && s[left])
		left++;
	while (ft_isinset(set, s[right - 1]) && right - 1 > 0)
		right--;
	size = right - left;
	size = (size <= 0) ? 0 : size;
	if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_memcpy(new, &s[left], size);
	new[size] = '\0';
	return (new);
}
