/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:09:46 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/17 19:16:57 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string(va_arg(ap, const char *));
	else if (specifier == 'p')
	{
		count = write(1, "0x", 2);
		count += print_address(va_arg(ap, unsigned long));
	}
	else if (specifier == 'd' || specifier == 'i')
		count = print_digit((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count = print_digit((unsigned int)va_arg(ap, int), 10, 0);
	else if (specifier == 'x')
		count = print_digit((long)va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count = print_digit((long)va_arg(ap, unsigned int), 16, 1);
	else if (specifier == '%')
		count = write(1, "%", 1);
	else
		count = write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += find_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
