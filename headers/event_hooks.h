/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:51:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 15:45:18 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_HOOKS_H
# define FT_EVENT_HOOKS_H

# include <stdlib.h>
# include "types.h"
# include "render.h"
# include "mlx.h"

# define STEP 0.0025f
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SHIFT 257
# define KEY_PRESS_CODE 02
# define KEY_RELEASE_CODE 03
# define MOTION_NOTIFY_CODE 06
# define STRUCTURE_NOTIFY_CODE 17

enum	e_masks
{
	KEY_PRESS_MASK = (1L << 0),
	KEY_RELEASE_MASK = (1L << 1),
	MOTION_NOTIFY_MASK = (1L << 13),
	STRUCTURE_NOTIFY_MASK = (1L << 17)
};

# define EVENT_MAX_SIZE 70000

char	g_event_array[EVENT_MAX_SIZE];

int		key_pressed(int keycode, t_game *data);
int		key_released(int keycode, t_game *data);
int		exit_hook(t_game *data);
int		motion_hook(int x, int y, t_game *data);

#endif
