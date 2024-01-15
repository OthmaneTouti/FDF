/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:39:29 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/15 16:11:58 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(t_point *point)
{
    int previous_x;

    point->x *= 10;
    point->y *= 10;
    point->z *= 5;
    previous_x = point->x;
    point->x = (previous_x - point->y) * cos(0.523599);
    point->y = -point->z + (previous_x + point->y) * sin(0.523599);
}

void projection(t_map *map, t_mlx_data *data)
{
    int i;
    int j;
    t_point **points;

    points = map->points;
    i = 0;
    while (i < map->dimensions[0])
    {
        j = 0;
        while (j < map->dimensions[1])
        {
            iso(&points[i][j]);
            j++;
        }
        i++;
    }
    render_point(data, map);
    plot_map(data, map);
}