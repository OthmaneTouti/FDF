/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:09 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/09 15:30:10 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_win(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit (0);
}

static int	key_press(int keycode, t_mlx_data *data)
{
    if (keycode == 53)
        close_win(data);
    return (0);
}

void win_init(void)
{
	t_mlx_data	data;
	
	data.mlx = mlx_init();
	if (!(data.mlx))
		return ;
	data.win = mlx_new_window(data.mlx, 640, 360, "fdf");
	if (!(data.win))
	{
		free(data.mlx);
		return ;
	}
	img_init(&data);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 17, 1L<<17, close_win, &data);
	mlx_loop(data.mlx);
}