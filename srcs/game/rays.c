/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:19:19 by tony              #+#    #+#             */
/*   Updated: 2020/06/05 05:40:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "types.h"
#include "utils.h"

void    Ray_update(t_ray *ray, t_vec2 pos)
{
    ray->pos = pos;
}

void    Ray_rotate(t_ray *ray, double theta, char clockwise)
{
    ray->angle += (clockwise) ? theta : -theta;
    ray->dir = rotate(ray->dir, theta, clockwise);
}

void    Ray_extend(t_ray *ray)
{
    ray->particle = add_vec2(ray->particle, ray->dir);
}

void    Rays_rotate(t_ray *rays, double theta, char clockwise)
{
    int index;

    index = 0;
    while (index < RAYS_NUMBER)
    {
        Ray_rotate(&rays[index], theta, clockwise);
        index++;
    }
}

void    Rays_update(t_ray *rays, t_vec2 pos)
{
    int index;

    index = 0;
    while (index < RAYS_NUMBER)
    {
        Ray_update(&rays[index], pos);
        index++;
    }
}

void    Ray_forEach(t_ray *rays, size_t len, void (*f)(t_ray*))
{
    size_t index;

    index = 0;
    while (index < len)
    {
        f(&rays[index++]);
    }
}