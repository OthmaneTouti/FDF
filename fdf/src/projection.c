/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:39:29 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/15 11:23:30 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(t_point *point)
{
	int tmp_x;

	tmp_x = (point->x * sqrt(2) / 2) - (point->y * sqrt(2) / 2);
	point->y = (point->x * sqrt(2) / 2) + (point->y * sqrt(2) / 2);
	point->x = tmp_x;
	point->y = (point->y * sqrt(3) / 3) - (point->z * sqrt(6) / 3);
}

void	projection(t_map *map, t_mlx_data *data)
{
	int	i;
	int	j;
	t_point	**points;

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
}