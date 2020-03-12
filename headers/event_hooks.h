/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:51:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/03/12 13:34:50 by bbellavi         ###   ########.fr       */
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

# define KEY_PRESS_CODE 02
# define KEY_RELEASE_CODE 03

# define KEY_PRESS_MASK (1L << 0)
# define KEY_RELEASE_MASK (1L << 1)

# define EVENT_MAX_SIZE 100
char	event_array[EVENT_MAX_SIZE];

#define STEP (1.0f / 1000.0f)

typedef enum	e_event_index
{
	I_KEY_DOWN,
	I_KEY_UP,
	I_KEY_LEFT,
	I_KEY_RIGHT
}				t_event_index;

// int     keyboard_hook(int keycode, t_game *data);
int		key_pressed(int keycode, t_game *data);
int		key_released(int keycode, t_game *data);

#   endif