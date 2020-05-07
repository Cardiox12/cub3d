/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:08:38 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/03 15:41:18 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"

float	to_radians(float degrees)
{
	return (degrees * M_PI / 180);
}

float	to_degrees(float radians)
{
	return (radians * 180 / M_PI);
}