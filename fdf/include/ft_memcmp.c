/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:30:03 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 19:36:25 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (n--)
	{
		if (*s1_temp != *s2_temp)
			return (*s1_temp - *s2_temp);
		else
		{
			s1_temp++;
			s2_temp++;
		}
	}
	return (0);
}
