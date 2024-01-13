/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:35 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/12 19:33:13 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



static	void populate_map(t_map *map, int fd, int lines, int rows)
{
	int i;
	int j;
	char **line;

	i = 0;
	while (i < lines)
	{
		j = 0;
		line = ft_split(get_next_line(fd), ' ');
		while (j < rows)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].z = ft_atoi(line[j]);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	// while (i < lines)
	// {
	// 	j = 0;
	// 	while (j < rows)
	// 	{
	// 		printf("x: %d, y: %d, z: %d\n", map->points[i][j].x, map->points[i][j].y, map->points[i][j].z);
	// 		j++;
	// 	}
	// 	i++;
	// }
}

void create_map(t_map * map, int lines, int rows)
{
    int 	i;

	i = 0;
    if (!lines || !rows)
        return ;
    map->points = (t_point **)malloc(sizeof(t_point *) * lines);
    if (!map->points)
        perror("Error allocating memory for points");
    while (i < lines)
    {
        map->points[i] = (t_point *)malloc(sizeof(t_point) * rows);
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


int get_coords(char *map_path, t_mlx_data *data)
{
    int 		fd;
	int			lines;
	int			rows;
	t_map		*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		perror("Error allocating memory for map");
    if (!data)
        return (1);
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    lines = ft_count_file_lines(fd);
    close(fd);
    fd = open(map_path, O_RDONLY);
	rows = ft_count_file_rows(fd, ' ');
	ft_printf("lines: %d, rows: %d\n", lines, rows);
	create_map(map, lines, rows);
	close(fd);
	fd = open(map_path, O_RDONLY);
	populate_map(map, fd, lines, rows);
    return (0);
}