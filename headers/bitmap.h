/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 04:07:30 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/31 04:40:58 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITMAP_H
# define FT_BITMAP_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdint.h>
#include "types.h"

#pragma pack(push, 1)

typedef struct	s_bitmap
{
	u_int16_t	bf_type;
	uint32_t	bf_size;
	u_int16_t	bf_reserved1;
	u_int16_t	bf_reserved2;
	uint32_t	bf_offset_bits;

	uint32_t	bi_size;
	uint32_t	bi_width;
	uint32_t	bi_height;
	u_int16_t	bi_planes;
	u_int16_t	bi_bit_count;
	uint32_t	bi_compression;
	uint32_t	bi_size_image;
	uint32_t	bi_x_ppm;
	uint32_t	bi_y_ppm;
	uint32_t	bi_clr_used;
	uint32_t	bi_clr_important;
}				t_bitmap;

#pragma pack(pop)

# define BMP_IMAGE_HEADER_SIZE 40
# define BMP_FILES_HEADER_SIZE 14
# define BITS_PER_PIXEL 8
# define MAGIC_VALUE 0x4d42
# define BMP_EXT ".bmp"
# define XPM_EXT ".xpm"

int		export_to_bmp(const char *filename, t_game *data);

#endif