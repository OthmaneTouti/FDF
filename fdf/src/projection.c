/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:39:29 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/11 13:02:07 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_point *point, t_mlx_data *data)
{
	int tmp_x;

	
	tmp_x = (point->x * (sqrt(2) / 2)) + (point->y * (-sqrt(2) / 2));
	point->y = (point->x * (sqrt(2) / 2)) + (point->y * (sqrt(2) / 2));
	point->x = tmp_x;
	point->y = point->y * (sqrt(3) / 3) - point->z * (sqrt(6) / 3);
	render_point(data, point);
}