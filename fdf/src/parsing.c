/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:35 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/09 14:42:28 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int parsing(char *file_name)
{
	char *line;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while((line = get_next_line(fd)))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}