/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:08:59 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/14 01:11:00 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types.h"

t_vec	add_vec(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_vec2	add_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2 ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_vec2	norm_vec(t_vec2 a)
{
	const int mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec2	res;

	res.x = a.x / (float)mag;
	res.y = a.y / (float)mag;
	return (res);
}