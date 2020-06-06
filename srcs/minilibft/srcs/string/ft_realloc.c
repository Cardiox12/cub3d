/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 23:29:37 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:27:50 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *new;

	new = malloc(newsize);
	if (new == NULL)
		return (NULL);
	ft_memset(new, 0, newsize);
	if (oldsize > newsize)
		ft_memcpy(new, ptr, newsize);
	else
		ft_memcpy(new, ptr, oldsize);
	free(ptr);
	return (new);
}
