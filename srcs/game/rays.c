/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:19:19 by tony              #+#    #+#             */
/*   Updated: 2020/06/05 21:51:45 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"

void	ray_update(t_ray *ray, t_vec2 pos)
{
	ray->pos = pos;
}

void	ray_rotate(t_ray *ray, double theta, char clockwise)
{
	ray->angle += (clockwise) ? theta : -theta;
	ray->dir = rotate(ray->dir, theta, clockwise);
}

void	rays_rotate(t_ray *rays, double theta, char clockwise)
{
	int index;

	index = 0;
	while (index < RAYS_NUMBER)
	{
		ray_rotate(&rays[index], theta, clockwise);
		index++;
	}
}

void	rays_update(t_ray *rays, t_vec2 pos)
{
	int index;

	index = 0;
	while (index < RAYS_NUMBER)
	{
		ray_update(&rays[index], pos);
		index++;
	}
}
