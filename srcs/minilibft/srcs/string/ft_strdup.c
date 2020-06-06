/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:44:17 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:28:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *src)
{
	const size_t	len = ft_strlen(src);
	char			*ret;

	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, src, sizeof(char) * (len + 1));
	return (ret);
}
