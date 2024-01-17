/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:16:45 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 16:24:23 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

void find_min_max(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->min[1] = map->points[0][0].x;
	map->min[0] = map->points[0][0].y;
	map->max[1] = map->points[0][0].x;
	map->max[0] = map->points[0][0].y;
	while (i < map->dimensions[0])
	{
		j = 0;
		while (j < map->dimensions[1])
		{
			map->min[1] = ft_min(map->min[1], map->points[i][j].x);
			map->min[0] = ft_min(map->min[0], map->points[i][j].y);
			map->max[1] = ft_max(map->max[1], map->points[i][j].x);
			map->max[0] = ft_max(map->max[0], map->points[i][j].y);
			j++;
		}
		i++;
	}
}

void find_min_max_z(t_map *map, int *min_z, int *max_z)
{
    int i;
    int j;
    int z;

    *min_z = INT_MAX;
    *max_z = INT_MIN;
    i = 0;
    while (i < map->dimensions[0]) {
        j = 0;
        while (j < map->dimensions[1])
		{
            z = map->points[i][j].z;
            if (z < *min_z)
                *min_z = z;
            if (z > *max_z)
                *max_z = z;
            j++;
        }
        i++;
    }
}

void clean_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->dimensions[0])
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	free(map);
	ft_printf("Map cleaned\n");
}