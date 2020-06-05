/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:22:11 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 05:22:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

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