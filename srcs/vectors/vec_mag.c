/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:18:47 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:18:36 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

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
