/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:18:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/28 01:28:59 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

#include <math.h>
#include "types.h"

// Vectors functions
t_vec2	rotate(t_vec2 u, double theta, char clockwise);
t_vec2	norm_vec2(t_vec2 a);
t_vec	norm_vec(t_vec a);
t_vec	neg_vec(t_vec a);
t_vec2	neg_vec2(t_vec2 a);
t_vec	add_vec(t_vec a, t_vec b);
t_vec2	add_vec2(t_vec2 a, t_vec2 b);
t_vec	mult_vec(t_vec a, float scalar);
t_vec2	mult_vec2(t_vec2 a, float scalar);
t_vec	to_vec(t_vec2 a);
t_vec2	to_vec2(t_vec a);
t_vec2	div_vec2(t_vec2 a, int scalar);
t_vec	div_vec(t_vec a, int scalar);
int		dist_vec(t_vec a, t_vec b);
int		dist_vec2(t_vec2 a, t_vec2 b);
float	dot_vec(t_vec a, t_vec b);
float	dot_vec2(t_vec2 a, t_vec2 b);
float	get_angle(t_vec a, t_vec b);
float	get_angle2(t_vec2 a, t_vec2 b);

float	to_radians(float degrees);
float	to_degrees(float radians);
int		vector_angle(t_vec2 vec);
int     is_wall(int c);

int		max(int a, int b);
int		min(int a, int b);

void	sort_pairs(t_pair *pairs, int size);

#endif