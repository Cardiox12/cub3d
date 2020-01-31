/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:25:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/31 20:04:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_std.h"
#include "get_next_line.h"
#include <stdio.h>

void    Debug_print_bits(int num)
{
    char bits;
    bits = sizeof(int) * 8;

    while (bits != 0)
    {
        bits--;
        if (num & (0x01 << bits))
            printf("1");
        else
            printf("0");
        if (bits % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

static int  is_texture(char *identifier)
{
    if (ft_strncmp(identifier, NORTH, ft_strlen(NORTH)) == 0)
        return (I_NORTH);
    else if (ft_strncmp(identifier, SOUTH, ft_strlen(SOUTH)) == 0)
        return (I_SOUTH);
    else if (ft_strncmp(identifier, EAST, ft_strlen(EAST)) == 0)
        return (I_EAST);
    else if (ft_strncmp(identifier, WEST, ft_strlen(WEST)) == 0)
        return (I_WEST);
    else if (ft_strncmp(identifier, SPRITE, ft_strlen(SPRITE)) == 0)
        return (I_SPRITE);
    return (NOT_FOUND);
}

static char *is_identifier(char *s)
{
    int index;

    index = 0;
    while (index < ID_SIZE)
    {
        if (ft_strncmp(s, identifiers[index], ft_strlen(identifiers[index])) == 0)
            return (identifiers[index]);
        index++;
    }
    return (NULL);
}

/* This function check if filename is valid by checking if it ends with .cub */

static int  is_valid_filename(const char *path)
{
    char    *ptr;
    size_t  size;
    
    size = ft_strlen(path);
    if (size > CUB_EXT_LENGTH)
    {
        ptr = (char*)&path[size - CUB_EXT_LENGTH];
        if (ft_strncmp(ptr, CUB_EXTENSION, CUB_EXT_LENGTH) == 0)
            return (TRUE);
    }
    return (FALSE);
}

size_t   array_length(char **str_arr)
{
    size_t length;

    length = 0;
    while (*str_arr != NULL)
    {
        length++;
        str_arr++;
    }
    return (length);
}

static void store_resolution_to_map(t_map *map, char *res)
{
    char **line;

    line = ft_split(res, ' ');
    if (line != NULL)
    {
        if (array_length(line) == 3)
        {
            map->resolution->x = ft_atoi(line[1]);
            map->resolution->y = ft_atoi(line[2]);
        }
        else
        {
            ft_putstr("Error\n");
            ft_putstr(ERR_RESOLUTION);
            exit(1);
        }
    }
}

static void store_texture_to_map(t_map *map, char *texture, int ident)
{
    char    **line;

    line = ft_split(texture, SPACE);
    if (line != NULL)
    {
        if (array_length(line) == 2)
        {
            if (ident == I_NORTH)
                map->textures->north = line[1];
            else if (ident == I_SOUTH)
                map->textures->south = line[1];
            else if (ident == I_EAST)
                map->textures->east = line[1];
            else if (ident == I_WEST)
                map->textures->west = line[1];
            else if (ident == I_SPRITE)
                map->textures->sprite = line[1];
        }
        else
        {
            ft_putstr("Error\n");
            ft_putstr(ERR_TEXTURE);
            exit(1);
        }
    }
}

static int is_color(char *ident)
{
    if (ft_strncmp(ident, FLOOR, ft_strlen(FLOOR)) == 0)
        return (I_FLOOR);
    else if (ft_strncmp(ident, CEIL, ft_strlen(CEIL)) == 0)
        return (I_CEIL);
    return (NOT_FOUND);
}

static int rgb_has_correc_range(int r, int g, int b)
{
    return (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
}

static void store_color_to_map(t_map *map, char *colors, int ident)
{
    char    **line;
    int     red;
    int     green;
    int     blue;

    while (*colors != '\0' && !(*colors > '0' && *colors < '9'))
        colors++;
    line = ft_split(colors, COMMA);
    if (line != NULL)
    {
        red = ft_atoi(line[0]);
        green = ft_atoi(line[1]);
        blue = ft_atoi(line[2]);
        if (array_length(line) == 3 && rgb_has_correc_range(red, green, blue))
        {
            if (ident == I_CEIL)
                map->ceil_color = ft_encode_rgb(red, green, blue);
            else if (ident == I_FLOOR)
                map->ground_color = ft_encode_rgb(red, green, blue);
        }
        else
        {
            ft_putstr("Error\n");
            ft_putstr(ERR_COLORS);
            exit(1);
        }
    }
}

static void store_to_map(t_map *map, char *identifier, char *s)
{
    const size_t    length = ft_strlen(identifier);
    int             ident;
    
    if (ft_strncmp(identifier, RES, length) == 0)
        store_resolution_to_map(map, s);
    else if ((ident = is_texture(identifier)) != NOT_FOUND)
        store_texture_to_map(map, s, ident);
    else if ((ident = is_color(identifier)) != NOT_FOUND)
        store_color_to_map(map, s, ident);
}

static void print_map(t_map *map)
{
    printf("Resolution :\n");
    printf("\tx = %i\n", map->resolution->x);
    printf("\ty = %i\n", map->resolution->y);

    printf("Textures :\n");
    printf("\tnorth = %s\n", map->textures->north);
    printf("\tsouth = %s\n", map->textures->south);
    printf("\twest = %s\n", map->textures->west);
    printf("\teast = %s\n", map->textures->east);
    printf("\tsprite = %s\n", map->textures->sprite);

    printf("Colors :\n");
    printf("\tceil = ");
    Debug_print_bits(map->ceil_color);
    printf("\tfloor = ");
    Debug_print_bits(map->ground_color);

    printf("Maps : \n");
    while (*map->map != NULL)
    {
        printf("\t%s\n", *map->map);
        map->map++;
    }
}

char    *append_to_str(char **dst, char *src)
{
    char *old;
    char *prev_str;

    if (*dst == NULL)
    {
        if ((*dst = ft_strndup(src, ft_strlen(src))) == NULL)
            return (NULL);
    }
    else
    {
        old = *dst;
        if ((prev_str = ft_strjoin(*dst, ";")) == NULL)
            return (NULL);
        if ((*dst = ft_strjoin(prev_str, src)) == NULL)
            return (NULL);
        free(old);
        free(prev_str);
    }
    return (*dst);
}

int     is_mapline(char *line)
{
    while (*line)
    {
        if (ft_strchr(MAP_SYMBOLS, *line) == NULL)
            return (0);
        line++;
    }
    return (1);
}

void    parse_map(const char *path, t_map *map)
{
    int         fd;
    char        *line;
    char        *identifier;
    char        *buffer;

    buffer = NULL;
    if (is_valid_filename(path))
    {
        fd = open(path, O_RDONLY);
        while (get_next_line(fd, &line) > 0)
        {
            if (*line != '\0')
            {
                line = ft_strtrim(line, " \n\t");
                if ((identifier = is_identifier(line)) != NULL)
                    store_to_map(map, identifier, line);
                else if (is_mapline(line))
                    append_to_str(&buffer, line);
            }
            free(line);
        }
        map->map = ft_split(buffer, ';');
        print_map(map);
    }
}
