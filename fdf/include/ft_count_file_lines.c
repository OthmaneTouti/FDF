/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_file_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:24:22 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/12 19:24:46 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_count_file_lines(int fd)
{
    int		lines;
    char	*line;

    lines = 0;
    while ((line = get_next_line(fd)))
    {
        if (!line)
            break;
        lines++;
        free(line);
    }
    return (lines);
}
