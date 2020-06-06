/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:25:41 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:22:37 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include "get_next_line.h"
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putnbr(int nbr);

#endif
