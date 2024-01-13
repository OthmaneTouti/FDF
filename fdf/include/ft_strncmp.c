/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:36:55 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/19 12:46:05 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	while (n-- && (*s1 || *s2))
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
