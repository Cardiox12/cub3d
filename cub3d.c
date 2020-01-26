/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 00:57:20 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int		main(void)
{
	t_mlx_infos infos;

	init_mlx_infos(&infos);
	if ((infos.mlx_ptr = mlx_init()) != NULL)
	{
		infos.win_ptr = mlx_new_window(infos.mlx_ptr, WIDTH, HEIGHT, "mlx window");
		ft_line(10, 10, 10, 100, &infos);
		mlx_key_hook(infos.win_ptr, escape_hook, NULL);
		mlx_loop(infos.mlx_ptr);
	}
}
