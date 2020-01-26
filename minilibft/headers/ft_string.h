/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:21:06 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 01:48:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_STRING_H
#   define FT_STRING_H

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s, size_t len);

#   endif