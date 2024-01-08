/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:48:16 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 16:22:32 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	char	*ptr_temp;

	ptr_temp = (char *) ptr;
	while (len)
	{
		*ptr_temp = value;
		ptr_temp++;
		len--;
	}
	return (ptr);
}
