/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:09 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:27:31 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_mlx_data *data)
{
	free(data->mlx);
	exit (0);
}

int	key_press(int keycode, t_mlx_data *data)
{
    if (keycode == 53)
        close_win(data);
    return (0);
}

t_mlx_data *win_init()
{
    t_mlx_data	*data;
    
    data = (t_mlx_data	*)malloc(sizeof(t_mlx_data));
    if (!data)
        return NULL;
    data->mlx = mlx_init();
    if (!(data->mlx))
    {
        free(data);
        return NULL;
    }
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "File de faire");
    if (!(data->win))
    {
        free(data->mlx);
        free(data);
        return NULL;
    }
    img_init(data);
    return (data);
}