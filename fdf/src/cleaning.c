/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:09:45 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/18 13:07:39 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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