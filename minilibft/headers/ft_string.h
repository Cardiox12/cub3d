/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:21:06 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/30 19:27:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_STRING_H
#   define FT_STRING_H

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char    **ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);

#   endif