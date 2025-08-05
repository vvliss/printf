/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:49:46 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/04 17:36:38 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define NPTRSIZE 5
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# else
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# endif

# define SUCCESS 1
# define ERROR -1

size_t	ft_print_spf(const char c, va_list args);
int		ft_printf(const char *str, ...);
size_t	ft_putchar(const char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(uintptr_t n, char *base, int base_len, char spf);

# define IS_SPECIFIER(c) (c == 'c' || c == 's' || c == 'p' || \
	c == 'd' || c == 'i' || c == 'u' || \
	c == 'x' || c == 'X' || c == '%') \

#endif