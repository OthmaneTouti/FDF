/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:35 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/18 13:07:53 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void process_line(t_map *map, char **line, int i, int j)
{
    char *comma_position;
	
	comma_position = ft_strchr(line[j], ',');
    if (comma_position)
        map->points[i][j].color = ft_atoi_base(comma_position + 3, 16);
    else
        map->points[i][j].color = -1;
    map->points[i][j].x = (int)j;
    map->points[i][j].y = (int)i;
    map->points[i][j].z = (int)ft_atoi(ft_strtrim(line[j], ","));
}

static void process_lines(t_map *map, int fd)
{
    int i;
    int j;
    char **line;

    i = 0;
    while (i < map->dimensions[0])
    {
        line = ft_split(get_next_line(fd), ' ');
        j = 0;
        while (j < map->dimensions[1])
        {
            if (check_digit(line[j]))
            {
                free(line);
                exit(1);
            }
            process_line(map, line, i, j);
            j++;
        }
        free(line);
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
        perror("Error: allocating memory for points");
    while (i < map->dimensions[0])
    {
        map->points[i] = (t_point *)malloc(sizeof(t_point) * map->dimensions[1]);
        if (!map->points[i])
        {
            while (i > 0)
                free(map->points[--i]);
            free(map);
            perror("Error: allocating memory for point");
        }
        i++;
    }
}

static void set_dimensions(t_map *map, int fd, char *map_path)
{
    map->dimensions[0] = ft_count_file_lines(fd);
    close(fd);
    open_file(&fd, map_path);
    map->dimensions[1] = ft_count_file_rows(fd, ' ');
    if (!map->dimensions[0] || !map->dimensions[1])
    {
        perror("Error: invalid map");
        exit(1);
    }
}

t_map *get_coords(char *map_path)
{
    int fd;
    t_map *map;

    open_file(&fd, map_path);
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        perror("Error allocating memory for map");
        exit(1);
    }
    set_dimensions(map, fd, map_path);
    create_map(map);
    close(fd);
    open_file(&fd, map_path);
    process_lines(map, fd);
    close(fd);
    return map;
}