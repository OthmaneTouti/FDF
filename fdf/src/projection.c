/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:39:29 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:20:39 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(t_3d_point *point)
{
    int 	previous_x;
	
    previous_x = point->x;
    point->x = (previous_x - point->y) * cos(0.523599);
    point->y = -point->z + (previous_x + point->y) * sin(0.523599);
}

static t_2d_map *create_2d_map(int dim_x, int dim_y)
{
    int i = 0;
    t_2d_map *map_2d = (t_2d_map *)malloc(sizeof(t_2d_map));
    if (!map_2d)
    {
        perror("Error allocating memory for map");
        exit(1);
    }
    map_2d->dimensions[0] = dim_x;
    map_2d->dimensions[1] = dim_y;
    map_2d->points = malloc(map_2d->dimensions[0] * sizeof(t_2d_point *));
    while (i < map_2d->dimensions[0])
    {
        map_2d->points[i] = malloc(map_2d->dimensions[1] * sizeof(t_2d_point));
        i++;
    }
    return map_2d;
}

static void verify_maps(t_2d_map *map_2d, t_map *map_3d)
{
	int i;
	int j;

	i = 0;
	while (i < map_2d->dimensions[0])
	{
		j = 0;
		while (j < map_2d->dimensions[1])
		{
			if (map_2d->points[i][j].x != map_3d->points[i][j].x
				|| map_2d->points[i][j].y != map_3d->points[i][j].y)
			{
				printf("Maps are different\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	printf("Maps are the same\n");
}

t_2d_map *projection(t_map *map_3d)
{
    int i = 0;
    int j;
    t_2d_map *map_2d;
    t_3d_point **points_3d = map_3d->points;

    map_2d = create_2d_map(map_3d->dimensions[0], map_3d->dimensions[1]);

    while (i < map_3d->dimensions[0])
    {
        j = 0;
        while (j < map_3d->dimensions[1])
        {
            iso(&points_3d[i][j]);
            map_2d->points[i][j].x = points_3d[i][j].x;
            map_2d->points[i][j].y = points_3d[i][j].y;
            j++;
        }
        i++;
    }
	verify_maps(map_2d, map_3d);
    return (map_2d);
}