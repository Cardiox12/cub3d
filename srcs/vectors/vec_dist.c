/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:25:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:20:31 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	dist_vec(t_vec a, t_vec b)
{
	const int dist = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);

	return (sqrt(dist));
}

double	dist_vec2(t_vec2 a, t_vec2 b)
{
	const int dist = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);

	return (sqrt(dist));
}
