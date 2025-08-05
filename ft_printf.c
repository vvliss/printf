/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:46:20 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/05 15:36:41 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_print_spf(const char c, va_list args)
{
	if(c == 'c')
		return(ft_putchar(va_arg(args, int)));
	else if(c == 's')
		return(ft_putstr(va_arg(args, char *)));
	else if(c == 'p')
		return(ft_putptr(va_arg(args, unsigned long)));
	else if(c == 'd' || c == 'i')
		return(ft_putnbr(va_arg(args, int), 10, c));
	else if(c == 'u')
		return(ft_putnbr(va_arg(args, unsigned int), 10, c));
	else if(c == 'x')
		return(ft_putnbr(va_arg(args, unsigned int), 16, c));
	else if(c == 'X')
		return(ft_putnbr(va_arg(args, unsigned int), 16, c));
	else if(c == '%')
		return(ft_putchar('%'));
	return(0);
}

int ft_printf(const char *str, ...)
{
	va_list args;
    size_t count;
	
	count = 0;
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            count += ft_print_spf(*str, args);
        }
        else
            count += ft_putchar(*str);
        str++;
    }
    va_end(args);
    return (count);
}
