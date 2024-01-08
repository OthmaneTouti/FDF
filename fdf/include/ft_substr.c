/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:47:50 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 18:51:13 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len || !len)
	{
		sub_s = (char *) malloc(sizeof(char));
		if (!sub_s)
			return (0);
		*sub_s = '\0';
		return (sub_s);
	}
	if (s_len - start < len)
		len = s_len - start;
	sub_s = (char *) malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (0);
	ft_strlcpy(sub_s, (s + start), len + 1);
	return (sub_s);
}
