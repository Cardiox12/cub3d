/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:19:26 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 16:49:04 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTORS_H
# define FT_VECTORS_H

# include <math.h>
# include "types.h"

# define CLOCKWISE 1
# define ANTI_CLOCKWISE 0

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
double	dist_vec(t_vec a, t_vec b);
double	dist_vec2(t_vec2 a, t_vec2 b);
float	dot_vec(t_vec a, t_vec b);
float	dot_vec2(t_vec2 a, t_vec2 b);
float	get_angle(t_vec a, t_vec b);
float	get_angle2(t_vec2 a, t_vec2 b);
float	mag_vec(t_vec a);
float	mag_vec2(t_vec2 a);
int		vector_angle(t_vec2 vec);

#endif
