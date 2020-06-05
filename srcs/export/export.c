/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 04:05:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/01 00:13:49 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

t_bitmap	create_bitmap(t_vec res)
{
	t_bitmap bitmap;

	bitmap = (t_bitmap){
		.bf_type = MAGIC_VALUE,
		.bf_size = res.x * res.y + BMP_IMAGE_HEADER_SIZE + BMP_FILES_HEADER_SIZE,
		.bf_reserved1 = 0,
		.bf_reserved2 = 0,
		.bf_offset_bits = 54,
		.bi_size = BMP_IMAGE_HEADER_SIZE,
		.bi_width = res.x,
		.bi_height = res.y,
		.bi_planes = 1,
		.bi_bit_count = 32,
		.bi_compression = 0,
		.bi_size_image = res.x * res.y * 3,
		.bi_x_ppm = 0,
		.bi_y_ppm = 0,
		.bi_clr_used = 0,
		.bi_clr_important = 0
	};
	return (bitmap);
}

int		export_to_bmp(const char *filename, t_game *data)
{
	const int		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, S_IRWXU);
	const t_bitmap	bmp = create_bitmap(data->map.resolution);
	t_vec			i;

	if (fd < 0)
		return (1);
	write(fd, &bmp, sizeof(bmp));
	i.y = 0;
	while (i.y < data->map.resolution.y)
	{
		i.x = (data->map.resolution.y - i.y - 1) * data->map.resolution.x;
		write(fd, &data->image.img_data_addr[i.x], sizeof(unsigned int) * data->map.resolution.x);
		i.y++;
	}
	return (0);
}