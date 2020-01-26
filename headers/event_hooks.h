/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:51:02 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 00:56:52 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef FT_EVENT_HOOKS_H
#   define FT_EVENT_HOOKS_H

#include <stdlib.h>
#include "mlx.h"

int     escape_hook(int keycode, void *param);

#   endif