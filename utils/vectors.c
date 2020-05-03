/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:08:59 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/03 03:16:10 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	mag_vec(t_vec a)
{
	const float squared = a.x * a.x + a.y * a.y;

	return (sqrt(squared));
}

float	mag_vec2(t_vec2 a)
{
	const float squared = a.x * a.x + a.y * a.y;

	return (sqrt(squared));
}

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

t_vec2	norm_vec2(t_vec2 a)
{
	const double mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec2	res;

	res.x = a.x / (float)mag;
	res.y = a.y / (float)mag;
	return (res);
}

t_vec	norm_vec(t_vec a)
{
	const double	mag = sqrt((a.x * a.x) + (a.y * a.y));
	t_vec			res;

	res.x = a.x / mag;
	res.y = a.y / mag;
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

int		dist_vec(t_vec a, t_vec b)
{
	const int dist = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	
	return (sqrt(dist));
}

int		dist_vec2(t_vec2 a, t_vec2 b)
{
	const int dist = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	
	return (sqrt(dist));
}

float	dot_vec(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y);
}

float	dot_vec2(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

float	get_angle(t_vec a, t_vec b)
{
	const float dot = dot_vec(a, b);

	return (acos(dot / (mag_vec(a) * mag_vec(b))));
}

float	get_angle2(t_vec2 a, t_vec2 b)
{
	const float dot = dot_vec2(a, b);

	return (acos(dot / (mag_vec2(a) * mag_vec2(b))));
}