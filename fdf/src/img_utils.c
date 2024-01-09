/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:29:19 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/09 15:38:28 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int render_rect(t_img_data *img)
{
    int	i;
    int j;

    i = 5;
    while (i < 20)
    {
        j = 5;
        while (j < 40)
            img_pix_put(img, j++, i, 0x00FF0000);
        ++i;
    }
    return (0);
}

static void	render_background(t_img_data *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < 360)
    {
        j = 0;
        while (j < 640)
            img_pix_put(img, j++, i, color);
        ++i;
    }
}

static int	render(t_mlx_data *data)
{
    if (data->win == NULL)
        return (1);
    render_background(&data->img, 0x00FFFFFF);
    render_rect(&data->img);
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    return (0);
}

void img_init(t_mlx_data *data)
{
	
	data->img.img = mlx_new_image(data->mlx, 640, 360);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
	render(data);
}