/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:51:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/04/09 14:35:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_EVENT_HOOKS_H
#   define FT_EVENT_HOOKS_H

#include <stdlib.h>
#include "types.h"
#include "render.h"
#include "mlx.h"

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2 

# define KEY_PRESS_CODE 02
# define KEY_RELEASE_CODE 03

# define KEY_PRESS_MASK (1L << 0)
# define KEY_RELEASE_MASK (1L << 1)

# define EVENT_MAX_SIZE 1024
char	event_array[EVENT_MAX_SIZE];

#define STEP (1.0f / 1000.0f)

// typedef enum	e_event_index
// {
// 	I_KEY_DOWN,
// 	I_KEY_UP,
// 	I_KEY_LEFT,
// 	I_KEY_RIGHT,
// 	I_KEY_W,
// 	I_KEY_A,
// 	I_KEY_S,
// 	I_KEY_D
// }				t_event_index;

// int     keyboard_hook(int keycode, t_game *data);
int		key_pressed(int keycode, t_game *data);
int		key_released(int keycode, t_game *data);

#   endif