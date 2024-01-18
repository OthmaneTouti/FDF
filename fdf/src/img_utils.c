
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:29:19 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/10 13:35:54 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Puts a pixel with the specified color at the given coordinates in the image.
 *
 * This function is used to set the color of a pixel at a specific position in the image.
 * The color parameter represents the RGB color value of the pixel.
 * The x and y parameters specify the coordinates of the pixel in the image.
 *
 * @param img The image data structure.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The RGB color value of the pixel.
 */
static void	img_pix_put(t_mlx_data *data, int x, int y, int color)
{
 	char    *pixel;
	t_img_data *img;
    int		i;

	img = &data->img;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
    i = img->bpp - 8;
    pixel = data->img.addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
	}
}

static void check_boundaries(uint32_t x, uint32_t y, int *offset_x, int *offset_y)
{
	while (x + *offset_x > WIDTH)
		*offset_x -= 1;
	while (y + *offset_y > HEIGHT)
		*offset_y -= 1;
}

void	ft_put_pixel(t_mlx_data *data, uint32_t x, uint32_t y, uint32_t color, t_map *map)
{
    int	offset_x;
    int	offset_y;

    // Calculate the position of the top-left corner of the map
    int map_x = map->points[0][0].x * map->scale;
    int map_y = map->points[0][0].y * map->scale;

    // Calculate the offsets based on the position of the top-left corner of the map
    offset_x = (WIDTH / 2) - map_x;
    offset_y = (HEIGHT / 2) - map_y;
	check_boundaries(x, y, &offset_x, &offset_y);
    img_pix_put(data, x + offset_x, y + offset_y, color);
}


void img_init(t_mlx_data *data)
{
	
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
		perror("Error creating image");
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		perror("Error getting image address");
}