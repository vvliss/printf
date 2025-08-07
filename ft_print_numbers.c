/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:48:07 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/07 16:55:47 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(unsigned long n, unsigned int base,
		const char *digits)
{
	int	count;
	int	result;

	count = 0;
	if (n >= base)
	{
		result = ft_putnbr_recursive(n / base, base, digits);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar(digits[n % base]);
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_putnbr(long n, int base, char spec)
{
	int			count;
	const char	*digits;

	count = 0;
	digits = "0123456789abcdef";
	if (spec == 'X')
		digits = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (-1);
	if ((spec == 'd' || spec == 'i') && n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	return (count + ft_putnbr_recursive((unsigned long)n,
			(unsigned int)base, digits));
}
