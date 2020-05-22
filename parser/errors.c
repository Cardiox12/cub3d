/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 15:45:25 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/23 00:35:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		Errors_print(unsigned int errors, int listall)
{
	int index;

	index = 0;
	while (index < ERR_ARRAY_SIZE)
	{
		if (errors & errors_array[index].mask)
		{
			ft_putstr(errors_array[index].strerror);
			ft_putchar('\n');
			if (!listall)
				return errors_array[index].mask;
		}
		index++;
	}
	return (errors_array[index].mask);
}