/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:24:27 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 15:07:56 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void find_gradient(t_point p0, t_point p1, t_point *coor)
{
    double ratio;
    int hypo;
    int curr;

    hypo = sqrt(pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2));
    curr = sqrt(pow(coor->x - p0.x, 2) + pow(coor->y - p0.y, 2));
    if (hypo != 0)
        ratio = (double)curr / hypo;
    else 
        ratio = 1.0;
    coor->color = p0.color * (1 - ratio) + p1.color * ratio;
}

static void calculate_color(int z, int min_z, int max_z, t_color *color)
{
    double ratio;

    if (z < 0) {
        // z is negative, color goes towards blue
        ratio = (double)(z - min_z) / (-min_z);
        color->r = (int)(255 * (1 - ratio));
        color->g = color->r;
        color->b = 255;
    } else if (z > 0) {
        // z is positive, color goes towards red
        ratio = (double)(z) / max_z;
        color->r = 255;
        color->g = (int)(255 * (1 - ratio));
        color->b = color->g;
    } else {
        // z is zero, color is white
        color->r = 255;
        color->g = 255;
        color->b = 255;
    }
}

static void assign_color_to_points(t_map *map, int min_z, int max_z)
{
    int i;
    int j;
    int z;
    t_color *color;

    color = (t_color *) malloc(sizeof(t_color));
	if (!color)
	{
		perror("Error allocating memory for color");
		exit(1);
	}
	
    i = 0;
    while (i < map->dimensions[0])
    {
        j = 0;
        while (j < map->dimensions[1])
        {
            if (map->points[i][j].color == -1)
            {
                z = map->points[i][j].z;
                calculate_color(z, min_z, max_z, color);
                map->points[i][j].color = (color->r << 16)
                    | (color->g << 8) | color->b;
            }
            j++;
        }
        i++;
    }
    free(color);
}

void assign_color(t_map *map)
{
    int min_z;
    int max_z;

    find_min_max_z(map, &min_z, &max_z);
    assign_color_to_points(map, min_z, max_z);
}

