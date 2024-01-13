/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:05 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 15:50:57 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_temp;

	s_temp = (char *)s;
	while (n)
	{
		if (*s_temp == (char)c)
			return ((void *)s_temp);
		s_temp++;
		n--;
	}
	return (0);
}
