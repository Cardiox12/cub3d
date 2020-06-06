/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:27:33 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;

	bytes = (unsigned char *)b;
	while (len-- != 0)
		bytes[len] = c;
	return (b);
}
