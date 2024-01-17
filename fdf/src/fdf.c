/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:57:10 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:35:45 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx_data	*data;
	t_map		*map;
	
	if (argc != 2)
		return (1);
	data = win_init();
	map = get_coords(argv[1]);
	scale(map);
	projection(map);
	mlx_hook(data->win, 2, 1L<<0, key_press, &data);
	mlx_hook(data->win, 17, 1L<<17, close_win, &data);
	plot_map(data, map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_loop(data->mlx);
	
	return (0);
}