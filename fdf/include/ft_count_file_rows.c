/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_file_rows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:22:46 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/12 19:23:22 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_count_file_rows(int fd, char c)
{
    char	*line;
	int		count;

    line = get_next_line(fd);
    if (!line)
        return (0);
	count = ft_count_words(line, c);
    return (free(line), count);
}
