/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:46:20 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/07 16:56:16 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 10, c));
	if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 10, c));
	if (c == 'x' || c == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), 16, c));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		result;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result = ft_handle_format(*format, args);
		}
		else
			result = ft_putchar(*format);
		if (result == -1)
			return (-1);
		count += result;
		format++;
	}
	va_end(args);
	return (count);
}
