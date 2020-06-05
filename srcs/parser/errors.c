/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 15:45:25 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 16:06:31 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		errors_print(unsigned int errors, int listall)
{
	int index;

	index = 0;
	ft_putstr(ERROR_BASE_MSG);
	while (index < ERR_ARRAY_SIZE)
	{
		if (errors & g_errors_array[index].mask)
		{
			ft_putstr(g_errors_array[index].strerror);
			ft_putchar('\n');
			if (!listall)
				return g_errors_array[index].mask;
		}
		index++;
	}
	return (g_errors_array[index].mask);
}

int		error_std(const char *exe)
{
	ft_putstr(ERROR_BASE_MSG);
	perror(exe);
	exit(1);
}