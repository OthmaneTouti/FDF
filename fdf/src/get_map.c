/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:35 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/10 15:43:36 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void get_point(char **strs)
{
	int i = 0;
	
	while (strs[i])
	{
		if (ft_strncmp(strs[i], "(null)", 6))
			printf("%s\n", strs[i]);
		i++;
	}
}

static char **get_strs(int fd)
{
	char	*line;
	char	**strs;

	
	while ((line = get_next_line(fd)))
	{
		strs = ft_split(line, ' ');
		get_point(strs);
	}
	free(line);
	return (strs);
}

int get_map(char *map_path)
{
	int 	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	get_strs(fd);
	return (0);
}