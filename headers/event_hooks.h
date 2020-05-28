/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:51:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/28 03:54:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_EVENT_HOOKS_H
#   define FT_EVENT_HOOKS_H

#include <stdlib.h>
#include "types.h"
#include "render.h"
#include "mlx.h"

# define STEP (1.0f / 700.0f)
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_SHIFT 257

# define KEY_PRESS_CODE 02
# define KEY_RELEASE_CODE 03
# define MOTION_NOTIFY_CODE 06
# define STRUCTURE_NOTIFY_CODE 17

# define KEY_PRESS_MASK (1L << 0)
# define KEY_RELEASE_MASK (1L << 1)
# define MOTION_NOTIFY_MASK (1L << 13)
# define STRUCTURE_NOTIFY_MASK (1L << 17)

# define EVENT_MAX_SIZE 1024
char	event_array[EVENT_MAX_SIZE];


int		key_pressed(int keycode, t_game *data);
int		key_released(int keycode, t_game *data);
int		exit_hook(t_game *data);
int		motion_hook(int x, int y, t_game *data);

#   endif