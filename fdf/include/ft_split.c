/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:23:27 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/27 12:24:40 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static size_t	count_splits(const char *s, char c)
{
	int		in_word;
	size_t	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

void	free_split(char **split_s, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		free(split_s[i]);
		i++;
	}
	free(split_s);
}

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**write_strings(const char *s, char c, char **split_s)
{
	int		i;
	size_t	len;

	i = 1;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		len = word_len(s, c);
		split_s[i] = (char *) malloc((len + 1) * sizeof(char));
		if (!split_s[i])
		{
			free_split(split_s, i);
			return (0);
		}
		ft_strlcpy(split_s[i], (const char *)s, len + 1);
		i++;
		s += len;
	}
	split_s[i] = 0;
	return (split_s);
}

char	**ft_split(const char *s, char c)
{
	char	**split_s;

	if (!s)
		return (0);
	split_s = (char **) malloc((count_splits(s, c) + 2) * sizeof(char *));
	if (!split_s)
		return (0);
	split_s[0] = (char *) malloc(6 * sizeof(char));
	split_s[0] = "(null)";
	return (write_strings(s, c, split_s));
}
