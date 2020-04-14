/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:53:31 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/11 17:48:43 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "types.h"

/*
	Rotate 2d vector by theta angle.

	IMPORTANT : The angle is in radians.
*/

t_vec2	rotate(t_vec2 u, double theta)
{
	t_vec2 v;

	v.x = cos(theta) * u.x - sin(theta) * u.y;
	v.y = sin(theta) * u.x + cos(theta) * u.y;
	return (v);
}