/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:18:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/03 03:15:04 by tony             ###   ########.fr       */
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

double	to_radians(double degrees);

#endif