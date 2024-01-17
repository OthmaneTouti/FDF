/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:35 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:37:25 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



static	void populate_map(t_map *map, int fd)
{
	int i;
	int j;
	char **line;

	i = 0;
	while (i < map->dimensions[0])
	{
		j = 0;
		line = ft_split(get_next_line(fd), ' ');
		while (j < map->dimensions[1])
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].z = ft_atoi(line[j]);
			j++;
		}
		i++;
	}
}

static void create_map(t_map * map)
{
    int 	i;

	i = 0;
    if (!map->dimensions[0] || !map->dimensions[1])
        return ;
    map->points = (t_point **)malloc(sizeof(t_point *) * map->dimensions[0]);
    if (!map->points)
        perror("Error allocating memory for points");
    while (i < map->dimensions[0])
    {
        map->points[i] = (t_point *)malloc(sizeof(t_point) * map->dimensions[1]);
        if (!map->points[i])
        {
            while (i > 0)
                free(map->points[--i]);
            free(map);
            perror("Error allocating memory for point");
        }
        i++;
    }
}


t_map *get_coords(char *map_path)
{
    int 		fd;
	t_map		*map;
	
	fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		perror("Error allocating memory for map");
    map->dimensions[0] = ft_count_file_lines(fd);
    close(fd);
    fd = open(map_path, O_RDONLY);
	map->dimensions[1] = ft_count_file_rows(fd, ' ');
	ft_printf("lines: %d, rows: %d\n", map->dimensions[0], map->dimensions[1]);
	create_map(map);
	close(fd);
	fd = open(map_path, O_RDONLY);
	populate_map(map, fd);
    return (map);
}