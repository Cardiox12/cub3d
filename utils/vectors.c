/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:08:59 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/24 14:26:09 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types.h"


t_vec	neg_vec(t_vec a)
{
	t_vec ret;

	ret.x = -a.x;
	ret.y = -a.y;
	return (ret);
}

t_vec2	neg_vec2(t_vec2 a)
{
	t_vec2 ret;

	ret.x = -a.x;
	ret.y = -a.y;
	return (ret);
}

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
	const double mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec2	res;

	res.x = a.x / (float)mag;
	res.y = a.y / (float)mag;
	return (res);
}

t_vec	mult_vec(t_vec a, float scalar)
{
	t_vec ret;

	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	return (ret);
}

t_vec2	mult_vec2(t_vec2 a, float scalar)
{
	t_vec2 ret;

	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	return (ret);
}

t_vec	to_vec(t_vec2 a)
{
	t_vec ret;

	ret.x = (int)a.x;
	ret.y = (int)a.y;
	return (ret);
}

t_vec2	to_vec2(t_vec a)
{
	t_vec2 ret;

	ret.x = (float)a.x;
	ret.y = (float)a.y;
	return (ret);
}