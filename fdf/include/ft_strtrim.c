/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:01:27 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 19:51:03 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_start(const char *s1, const char *set)
{
	size_t	count;

	count = 0;
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
		count++;
	}
	return (count);
}

static size_t	count_end(const char *s1, const char *set, size_t len)
{
	size_t	count;

	count = 0;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
	{
		len--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	start = count_start(s1, set);
	end = count_end(s1, set, len);
	if (start >= len)
		return (ft_strdup(""));
	trimmed = ft_substr(s1, start, len - start - end);
	return (trimmed);
}
