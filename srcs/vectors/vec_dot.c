/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:25:58 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 05:26:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	dot_vec(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y);
}

float	dot_vec2(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}