/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:41 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 17:05:03 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str) || *str == '+' || *str == '-'
		|| (*str >= '0' && *str <= '9'))
	{
		if ((*str == '+' || *str == '-')
			&& !(*(str + 1) >= '0' && *(str + 1) <= '9'))
			return (num);
		else if (*str == '-' && sign == 1)
			sign = -1;
		else if (*str >= '0' && *str <= '9')
		{
			while (*str && (*str >= '0' && *str <= '9'))
			{
				num = num * 10 + (*str - '0');
				str++;
			}
			return (num * sign);
		}
		str++;
	}
	return (num * sign);
}
