/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:45:36 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/25 01:46:09 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stddef.h>
#include <limits.h>

#	define HEIGHT 500
#	define WIDTH 500

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	if ((mlx_ptr = mlx_init()) != NULL)
	{
		win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "mlx window");
		mlx_loop(mlx_ptr);
	}
}
