/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:51 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:18:22 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec	to_vec(t_vec2 a)
{
	t_vec ret;

	ret.x = (int)a.x;
	ret.y = (int)a.y;
	return (ret);
}

t_vec2	to_vec2(t_vec a)
{
	t_vec2 ret;

	ret.x = (float)a.x;
	ret.y = (float)a.y;
	return (ret);
}
