/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_to_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:39:12 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:27:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlen_to_sep(const char *s, unsigned char c)
{
	const char *final_s = s;

	while (*s != '\0' && *s != c)
		s++;
	return (s - final_s);
}
