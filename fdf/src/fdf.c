/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:57:10 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/12 18:39:50 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx_data	*data;
	
	if (argc != 2)
		return (1);
	data = win_init();
	mlx_hook(data->win, 2, 1L<<0, key_press, &data);
	mlx_hook(data->win, 17, 1L<<17, close_win, &data);
	get_coords(argv[1], data);
	mlx_loop(data->mlx);
	
	return (0);
}