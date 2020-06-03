/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:48:41 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/03 04:19:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define FOUND 1
# define NOT_FOUND -1
# define RET_ERROR 1
# define RET_NO_ERROR 0
# define ERR_ARRAY_SIZE 21

typedef struct	s_errors
{
	unsigned int	mask;
	char			*strerror;
}				t_errors;

enum	e_err_code
{
	CODE_ERR_MAP_CLOSE_ERROR		= (1U),
	CODE_ERR_MAP_CONFIG_ERROR		= (1U << 1),
	CODE_ERR_COLOR_OUT_OF_RANGE 	= (1U << 2),
	CODE_ERR_COLOR_MISSING			= (1U << 3),
	CODE_ERR_COLOR_BAD_FORMAT		= (1U << 4),
	CODE_ERR_TEXTURE_BAD_INDENT 	= (1U << 5),
	CODE_ERR_RESOLUTION_MISSING		= (1U << 6),
	CODE_ERR_CONF_OPEN_ERROR		= (1U << 7),
	CODE_ERR_BAD_FILE_EXT			= (1U << 8),
	CODE_ERR_INCONSISTENT_SPECS 	= (1U << 9),
	CODE_ERR_BAD_CHARS_IN_COLORS	= (1U << 10),
	CODE_ERR_DUPLICATE_SPECS		= (1U << 11),
	CODE_ERR_TEXTURE_PATH_MISSING	= (1U << 12),
	CODE_ERR_BAD_SPEC				= (1U << 13),
	CODE_ERR_RES_MISSING_PARAM		= (1U << 14),
	CODE_ERR_BAD_CHARS_IN_RES_FIELD = (1U << 15),
	CODE_ERR_MLX_FAILED_TO_INIT		= (1U << 16),
	CODE_ERR_IMG_FAILED_TO_INIT 	= (1U << 17),
	CODE_ERR_WIN_FAILED_TO_INIT		= (1U << 18),
	CODE_ERR_LOADING_TEXTURE		= (1U << 19),
	CODE_ERR_INVALID_OPT			= (1U << 20)
};

static const t_errors errors_array[ERR_ARRAY_SIZE] = {
	{CODE_ERR_MAP_CLOSE_ERROR, "Map isn't closed properly"},
	{CODE_ERR_MAP_CONFIG_ERROR, "Map contains incorrect characters"},
	{CODE_ERR_COLOR_OUT_OF_RANGE, "Color out of range, should be [0 ; 255]"},
	{CODE_ERR_COLOR_MISSING, "Missing color"},
	{CODE_ERR_COLOR_BAD_FORMAT, "Color not well formatted"},
	{CODE_ERR_TEXTURE_BAD_INDENT, "Texture bad indented"},
	{CODE_ERR_RESOLUTION_MISSING, "Resolution is missing one parameter"},
	{CODE_ERR_CONF_OPEN_ERROR, "Error while opening configuration file"},
	{CODE_ERR_BAD_FILE_EXT, "File extension not valid, .cub expected"},
	{CODE_ERR_INCONSISTENT_SPECS, "Inconsistent number of specifiers"},
	{CODE_ERR_BAD_CHARS_IN_COLORS, "Bad characters in color field"},
	{CODE_ERR_DUPLICATE_SPECS, "Duplicate specs"},
	{CODE_ERR_TEXTURE_PATH_MISSING, "Texture path is missing"},
	{CODE_ERR_BAD_SPEC, "Bad specifier"},
	{CODE_ERR_RES_MISSING_PARAM, "Resolution missing height"},
	{CODE_ERR_BAD_CHARS_IN_RES_FIELD, "Bad characters in resolution field"},
	{CODE_ERR_MLX_FAILED_TO_INIT, "Mlx failed to init"},
	{CODE_ERR_IMG_FAILED_TO_INIT, "Image failed to init"},
	{CODE_ERR_WIN_FAILED_TO_INIT, "Window failed to init"},
	{CODE_ERR_LOADING_TEXTURE, "Error loading texture"},
	{CODE_ERR_INVALID_OPT, "Invalid option"}
};

#endif