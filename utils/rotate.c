/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:53:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/11 22:23:45 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types.h"

/*
	Rotate 2d vector by theta angle.

	IMPORTANT : The angle is in radians.
*/

t_vec2	rotate(t_vec2 u, double theta, char clockwise)
{
	t_vec2 v;

	if (clockwise == CLOCKWISE)
	{
		v.x = cos(theta) * u.x - sin(theta) * u.y;
		v.y = sin(theta) * u.x + cos(theta) * u.y;
	}
	else
	{
		v.x = cos(theta) * u.x + sin(theta) * u.y;
		v.y = -sin(theta) * u.x + cos(theta) * u.y;
	}
	return (v);
}