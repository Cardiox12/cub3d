/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encode_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:41:19 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/26 14:04:54 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (((red & 0x0ff) << 16) | ((green & 0x0ff) << 8)| (blue & 0x0ff));
}