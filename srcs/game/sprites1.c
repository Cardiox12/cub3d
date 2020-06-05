/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:19:52 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 21:10:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	init_sprite(t_game *data, int i)
{
	data->map.sprites.sprite = (t_vec2){
		data->map.sprites.sprites[data->camera.sprite_order[i]].pos.x
		- data->camera.pos.x,
		data->map.sprites.sprites[data->camera.sprite_order[i]].pos.y
		- data->camera.pos.y,
	};
	data->map.sprites.transform = (t_vec2){
		data->map.sprites.inv_det *
		(data->camera.plan_front.y * data->map.sprites.sprite.x
		- data->camera.plan_front.x * data->map.sprites.sprite.y),
		data->map.sprites.inv_det *
		(-data->camera.plan_right.y * data->map.sprites.sprite.x
		+ data->camera.plan_right.x * data->map.sprites.sprite.y)
	};
	data->map.sprites.v_move_screen =
	data->map.sprites.sprites[data->camera.sprite_order[i]].v_move
	/ data->map.sprites.transform.y;
	data->map.sprites.sprite_screen_x =
	(int)((data->map.resolution.x / 2) *
	(1 + data->map.sprites.transform.x / data->map.sprites.transform.y));
	data->map.sprites.sprite_res.y = abs(
		(int)(data->map.resolution.y / data->map.sprites.transform.y))
		/ data->map.sprites.sprites[data->camera.sprite_order[i]].v_div;
}

static void	init_draw_variables(t_game *data, int i)
{
	data->map.sprites.draw_start.y = -data->map.sprites.sprite_res.y / 2
	+ data->map.resolution.y / 2 + data->map.sprites.v_move_screen;
	if (data->map.sprites.draw_start.y < 0)
		data->map.sprites.draw_start.y = 0;
	data->map.sprites.draw_end.y = data->map.sprites.sprite_res.y / 2
	+ data->map.resolution.y / 2 + data->map.sprites.v_move_screen;
	if (data->map.sprites.draw_end.y >= data->map.resolution.y)
		data->map.sprites.draw_end.y = data->map.resolution.y - 1;
	data->map.sprites.sprite_res.x = abs(
		(int)(data->map.resolution.y / data->map.sprites.transform.y))
		/ data->map.sprites.sprites[data->camera.sprite_order[i]].u_div;
	data->map.sprites.draw_start.x = -data->map.sprites.sprite_res.x / 2
	+ data->map.sprites.sprite_screen_x;
	if (data->map.sprites.draw_start.x < 0)
		data->map.sprites.draw_start.x = 0;
	data->map.sprites.draw_end.x = data->map.sprites.sprite_res.x / 2
	+ data->map.sprites.sprite_screen_x;
	if (data->map.sprites.draw_end.x >= data->map.resolution.x)
		data->map.sprites.draw_end.x = data->map.resolution.x - 1;
}

static void	set_sprite_color(t_game *data)
{
	uint32_t color;

	if (data->map.sprites.tex.x >= 0
	&& data->map.sprites.tex.x < data->map.sprites.tex_res.x
	&& data->map.sprites.tex.y >= 0
	&& data->map.sprites.tex.y < data->map.sprites.tex_res.y)
	{
		color = get_color(
			&data->map.textures[IDX_SPRITE].image,
			data->map.sprites.tex, data->map.sprites.tex_res.x);
		if ((color & 0x00FFFFFF) != 0)
			set_color(data, data->map.sprites.stripe, color);
	}
}

static void	draw_sprites(t_game *data)
{
	int d;

	if (data->map.sprites.transform.y > 0 && data->map.sprites.stripe.x > 0
	&& data->map.sprites.stripe.x < data->map.resolution.x
	&& data->map.sprites.transform.y <
	data->camera.zbuffer[data->map.sprites.stripe.x])
	{
		data->map.sprites.stripe.y = data->map.sprites.draw_start.y;
		while (data->map.sprites.stripe.y < data->map.sprites.draw_end.y)
		{
			d = (data->map.sprites.stripe.y - data->map.sprites.v_move_screen)
			* 256 - data->map.resolution.y * 128
			+ data->map.sprites.sprite_res.y * 128;
			data->map.sprites.tex.y = ((d * data->map.sprites.tex_res.y)
			/ data->map.sprites.sprite_res.y) / 256;
			set_sprite_color(data);
			data->map.sprites.stripe.y++;
		}
	}
	data->map.sprites.stripe.x++;
}

void		cast_sprites(t_game *data)
{
	int		i;

	data->map.sprites.inv_det = 1.0 / (data->camera.plan_right.x
	* data->camera.plan_front.y - data->camera.plan_front.x
	* data->camera.plan_right.y);
	data->map.sprites.tex_res = (t_vec){
		data->map.textures[IDX_SPRITE].width,
		data->map.textures[IDX_SPRITE].height};
	sort_sprites_dist(data);
	i = 0;
	while (i < data->map.sprites.cursor)
	{
		init_sprite(data, i);
		init_draw_variables(data, i++);
		data->map.sprites.stripe.x = data->map.sprites.draw_start.x;
		while (data->map.sprites.stripe.x < data->map.sprites.draw_end.x)
		{
			data->map.sprites.tex.x = (int)(256 * (data->map.sprites.stripe.x
			- (-data->map.sprites.sprite_res.x / 2
			+ data->map.sprites.sprite_screen_x)) * data->map.sprites.tex_res.x
			/ data->map.sprites.sprite_res.x) / 256;
			draw_sprites(data);
		}
	}
}
