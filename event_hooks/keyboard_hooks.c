/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:44:00 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/29 11:28:12 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_hooks.h"
#include <stdio.h>
#define ESC_KEY 53

int     keyboard_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC_KEY)
		exit(0);
    return (0);
}