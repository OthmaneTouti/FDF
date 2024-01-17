/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:57:10 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:21:34 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx_data	*data;
	t_map		*map_3d;
	t_2d_map	*map_2d;
	
	if (argc != 2)
		return (1);
	map_3d = get_coords(argv[1]);
	map_2d = projection(map_3d);
	find_min_max(map_2d);
	data = win_init(map_2d);
	mlx_hook(data->win, 2, 1L<<0, key_press, &data);
	mlx_hook(data->win, 17, 1L<<17, close_win, &data);
	scale(map_2d, data);
	plot_map(data, map_2d);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_loop(data->mlx);
	
	return (0);
}