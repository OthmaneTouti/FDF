/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:36:18 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:21:32 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_plot_line_low(t_2d_point p0, t_2d_point p1, t_mlx_data *data, t_2d_map *map)
{
    t_plot_line_tools	plt;
    t_3d_point				coor;
    int 				abs_dx;
	int					abs_dy;

    plt.dx = p1.x - p0.x;
    plt.dy = p1.y - p0.y;
    plt.yi = 1;
    if (plt.dy < 0)
        plt.yi = -1;
    abs_dx = abs(plt.dx);
    abs_dy = abs(plt.dy);
    plt.d = (2 * abs_dy) - abs_dx;
    coor.x = p0.x;
    coor.y = p0.y;
    while (coor.x <= p1.x)
    {
        ft_put_pixel(data, coor.x, coor.y, 0xFFFFFF, map);
        if (plt.d > 0)
        {
            coor.y += plt.yi;
            plt.d -= 2 * abs_dx;
        }
        plt.d += 2 * abs_dy;
        coor.x++;
    }
}

static void	ft_plot_line_high(t_2d_point p0, t_2d_point p1, t_mlx_data *data, t_2d_map *map)
{
    t_plot_line_tools	plt;
    t_3d_point				coor;
	int					abs_dx;
	int					abs_dy;

    plt.dx = p1.x - p0.x;
    plt.dy = p1.y - p0.y;
    plt.xi = 1;
    if (plt.dx < 0)
        plt.xi = -1;
	abs_dx = abs(plt.dx);
    abs_dy = abs(plt.dy);
    plt.d = (2 * abs_dx) - abs_dy;
    coor.x = p0.x;
    coor.y = p0.y;
    while (coor.y <= p1.y)
    {
		//ft_printf("coord y: %d, target y: %d\n", coor.y, p1.y);
        ft_put_pixel(data, coor.x, coor.y, 0xFFFFFF, map);
        if (plt.d > 0)
        {
            coor.x += plt.xi;
            plt.d -= 2 * abs_dy;
        }
        plt.d += 2 * abs_dx;
        coor.y++;
    }
}

static void	ft_plot_line(t_2d_point p0, t_2d_point p1, t_mlx_data *data, t_2d_map *map)
{
	int	dx;
	int	dy;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	if (abs(dx) > abs(dy))
	{
		if (p1.x - p0.x > 0)
			ft_plot_line_low(p0, p1, data, map);
		else
			ft_plot_line_low(p1, p0, data, map);
	}
	else
	{
		if (p1.y - p0.y > 0)
			ft_plot_line_high(p0, p1, data, map);
		else
			ft_plot_line_high(p1, p0, data, map);
	}
}

void plot_map(t_mlx_data *data, t_2d_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->dimensions[0])
    {
        j = 0;
        while (j < map->dimensions[1])
        {
            if (j < map->dimensions[1] - 1)
                ft_plot_line(map->points[i][j], map->points[i][j + 1], data, map);
            if (i < map->dimensions[0] - 1)
                ft_plot_line(map->points[i][j], map->points[i + 1][j], data, map);
            j++;
        }
        i++;
    }
}
