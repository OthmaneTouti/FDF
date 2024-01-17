/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:04:23 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 15:22:31 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void scale(t_map *map)
{
	int	i;
	int	j;

	map->scale = ft_min((float)WIDTH / (float)(map->dimensions[1] * 5),
	(float)HEIGHT / (float)(map->dimensions[0] * 5));
	i = 0;
	while (i < map->dimensions[0])
	{
		j = 0;
		while (j < map->dimensions[1])
		{
			map->points[i][j].x *= map->scale;
			map->points[i][j].y *= map->scale;
			map->points[i][j].z *= map->scale / 3;
			j++;
		}
		i++;
	}
}