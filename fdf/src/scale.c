/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:04:23 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:13:17 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void scale(t_2d_map *map_2d, t_mlx_data *data)
{
	int	i;
	int	j;

	map_2d->scale = ft_min((float)data->width / (float)(map_2d->dimensions[1] * 5),
	(float)data->height / (float)(map_2d->dimensions[0] * 5));
	i = 0;
	while (i < map_2d->dimensions[0])
	{
		j = 0;
		while (j < map_2d->dimensions[1])
		{
			map_2d->points[i][j].x *= map_2d->scale;
			map_2d->points[i][j].y *= map_2d->scale;
			j++;
		}
		i++;
	}
}