/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:17:24 by ottouti           #+#    #+#             */
/*   Updated: 2023/10/23 19:29:50 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	check_sign(long n)
{
	int	is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	return (is_negative);
}

static size_t	count_digits(long n)
{
	size_t	len;

	len = (n == 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	write_str(long n, char *num_str, size_t len, int is_negative)
{
	if (is_negative)
	{
		*num_str = '-';
		num_str++;
		n = -n;
	}
	num_str[len] = '\0';
	while (len--)
	{
		num_str[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*num_str;
	int		is_negative;
	long	ln;

	ln = (long)n;
	is_negative = check_sign(ln);
	len = count_digits(ln);
	num_str = (char *) malloc((len + 1 + is_negative));
	if (!num_str)
		return (0);
	write_str(ln, num_str, len, is_negative);
	return (num_str);
}
