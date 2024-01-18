/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:38:13 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/18 12:20:18 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int check_digit(char *str)
{
	char	*trimmed_str;
	int		i;
	
	if (ft_strncmp(str, "(null)", 6) == 0)
		return (0);
	trimmed_str = ft_strtrim(str, ",");
	i = 0;
	while (trimmed_str[i])
	{
		if (trimmed_str[i] == ',')
			break ;
		if (!ft_isdigit(trimmed_str[i]) && trimmed_str[i] != '-'
			&& trimmed_str[i] != '+')
		{
			ft_printf("Error: Invalid map (invalid coordinates)\n");
			free(trimmed_str);
			return (1);
		}
		i++;
	}
	free(trimmed_str);
	return (0);
}
