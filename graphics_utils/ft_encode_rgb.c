/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encode_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:41:19 by bbellavi          #+#    #+#             */
/*   Updated: 2020/02/19 15:53:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red | (green << 8) | (blue << 16));
}