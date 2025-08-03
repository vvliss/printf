/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:48:07 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/03 18:04:28 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


//this function handles if n is neg
//checks the prefix
//prints to stdout & returns the number of chars
size_t ft_putnbr_base(uintptr_t n, char *base, size_t len, char spf)
{
	size_t count;
	size_t i;
	char buffer[20];
	
	count = 0;
	i = 0;
	if (spf == 'p' && n == 0)
		return ft_putstr("(nil)");
	if(spf == 'p')
		count += ft_putstr("0x");
}
size_t	ft_putchar(const char c)
{
	if(write (1, &c, 1) == -1)
		return(-1);
	return (1);
}
size_t	ft_putstr(const char *str)
{
	size_t	count;

	if (!str)
		return (ft_putstr("(null)"));
	count = 0;
	while (str[count])
	{
		write (1, &str[count], 1);
		++count;
	}
	return (count);
}

//converting it to a different base 
//(e.g., binary, hexadecimal, etc.).
size_t ft_print_base()
{
	
}
