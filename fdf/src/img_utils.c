
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
static void	img_pix_put(t_img_data *img, int x, int y, int color)
{
 	char    *pixel;
    int		i;

    i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
	}
}



int	render_point(t_mlx_data *data, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->dimensions[0])
	{
		j = 0;
		while (j < map->dimensions[1])
		{
			img_pix_put(&data->img, map->points[i][j].x*10+(640/2), map->points[i][j].y*10+(360/2), 0xFFFFFF);
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    return (0);
}

void img_init(t_mlx_data *data)
{
	
	data->img.img = mlx_new_image(data->mlx, 640, 360);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
}