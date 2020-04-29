/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:19:19 by tony              #+#    #+#             */
/*   Updated: 2020/04/29 19:06:03 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"

void    Ray_update(t_ray *ray, t_vec2 pos)
{
    ray->pos = pos;
}

void    Ray_rotate(t_ray *ray, double theta, char clockwise)
{
    ray->dir = rotate(ray->dir, theta, clockwise);
}

void    Ray_extend(t_ray *ray)
{
    const t_vec2 dir = add_vec2(ray->pos, ray->dir);

    ray->proj = add_vec2(ray->proj, dir);
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