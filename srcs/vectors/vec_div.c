/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:24:23 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:20:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec2	div_vec2(t_vec2 a, int scalar)
{
	t_vec2 ret;

	ret.x = a.x / scalar;
	ret.y = a.y / scalar;
	return (ret);
}

t_vec	div_vec(t_vec a, int scalar)
{
	t_vec ret;

	ret.x = a.x / scalar;
	ret.y = a.y / scalar;
	return (ret);
}
