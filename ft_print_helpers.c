/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:48:07 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/05 19:44:39 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putchar(const char c)
{
	if(write (1, &c, 1) == -1)
		return(-1);
	return (1);
}
int ft_putstr(char *str)
{
    int count;
	int result;

    if (!str)
        return (ft_putstr("(null)"));
	count = 0;
    while (*str)
    {
		result = ft_putchar(*str);
        if (result == -1)
            return (-1);
        count += result;
		str++;
    }
    return (count);
}
static int ft_print_hex(unsigned long n)
{
	int count;
	char *dgs;
	
	count = 0;
	dgs = "0123456789abcdef";

	if (n >= 16)
		count += ft_print_hex(n / 16);
	count += ft_putchar(dgs[n % 16]);
	return(count);
}

int ft_putptr(unsigned long n)
{
	int count;

	count = 0;
	if(!n)
		return(ft_putstr("0x0"));
	count += ft_putstr("0x");
	
}

static int ft_print_digits(long n, int base, char *dgs)
{
	int count;

	count = 0;
	if(n >= base)
		count += ft_print_digits(n / base, base, dgs);
	count += ft_putchar(dgs[n % base]);
	return(count);
}


int ft_putnbr(long n, int base, char spf)
{
	int count;
	char *l_hex;
	char *u_hex;
	char *dgs;

	count = 0;
	l_hex = "0123456789abcdef";
	u_hex = "0123456789ABCDEF";
	dgs = l_hex;
	if(spf == 'X')
		dgs = u_hex;
	if((spf == 'd' || spf == 'i') && n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if(spf == 'u' || spf == 'x' || spf == 'X')
		n = (unsigned int)n;
	return(count + ft_print_digits(n, base, dgs));
}