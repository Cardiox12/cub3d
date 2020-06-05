/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:18:15 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 16:48:00 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <math.h>
# include <stdlib.h>
# include "types.h"
# include "mlx.h"

float	to_radians(float degrees);
float	to_degrees(float radians);
int		is_wall(int c);

int		max(int a, int b);
int		min(int a, int b);
void	check_screen_size(t_game *data);

void	sort_pairs(t_pair *pairs, int size);
void	free_game(t_game *data);

#endif
