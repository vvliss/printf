/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:41:44 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/07 16:56:37 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;
	int	result;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		result = ft_putchar(*s);
		if (result == -1)
			return (-1);
		count += result;
		s++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	result;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr(PTRNULL));
	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	count += result;
	result = ft_putnbr((unsigned long)ptr, 16, 'x');
	if (result == -1)
		return (-1);
	return (count + result);
}
