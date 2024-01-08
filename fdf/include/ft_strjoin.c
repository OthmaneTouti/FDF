/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:22 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 18:40:49 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_join;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s_join = (char *) malloc(len1 + len2 + 1);
	if (!s_join)
		return (0);
	ft_memmove((void *)s_join, (const void *)s1, len1);
	ft_memmove((void *)(s_join + len1), (const void *)s2, len2 + 1);
	return (s_join);
}
