/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/26 00:56:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"

int     escape_hook(int keycode, void *param)
{
    (void)param;
    (void)keycode;
    exit(1);
}