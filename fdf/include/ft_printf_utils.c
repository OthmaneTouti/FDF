/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:01:23 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/17 19:16:49 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_address(unsigned long address)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (address < 16)
		return (write(1, &symbols[address], 1));
	else
	{
		count = print_address(address / 16);
		return (count + print_address(address % 16));
	}
}

int	print_char(int c)
{
	if (c == 0)
		return (write(1, "\0", 1));
	return (write(1, &c, 1));
}

int	print_digit(long n, int base, int upper)
{
	int		count;
	char	*symbols;

	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, upper) + 1);
	}
	if (upper)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base, upper);
		return (count + print_digit(n % base, base, upper));
	}
}

int	print_string(const char *str)
{
	int			count;
	const char	*null_str;

	count = 0;
	null_str = "(null)";
	if (!str)
	{
		count = print_string(null_str);
		return (count);
	}
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
