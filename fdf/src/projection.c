/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:39:29 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:32:23 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(t_point *point)
{
    int 	previous_x;
	
    previous_x = point->x;
    point->x = (previous_x - point->y) * cos(0.523599);
    point->y = -point->z + (previous_x + point->y) * sin(0.523599);
}

void projection(t_map *map)
{
    int i = 0;
    int j;
    t_point **points = map->points;

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
}