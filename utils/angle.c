/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:08:38 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/28 01:28:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"

float	to_radians(float degrees)
{
	return (degrees * M_PI / 180);
}

float	to_degrees(float radians)
{
	return (radians * 180 / M_PI);
}

int vector_angle(t_vec2 vec)
{
	int ret;

	if (vec.x == 0)
	{
		if (vec.y > 0)
			return (90);
		if (vec.y == 0)
			return (0);
		else
			return (270);
	}
	else if (vec.y == 0)
		return (vec.x >= 0) ? 0 : 180;
	ret = to_degrees(atanf(vec.y / vec.x));
	if (vec.x < 0 && vec.y < 0)
		ret = 180 + ret;
	else if (vec.x < 0)
		ret = 180 + ret;
	else if (vec.y < 0)
		ret = 270 + (90 + ret);
	return ret;
}