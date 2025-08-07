/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:49:46 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/07 16:55:59 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# if defined(__linux__)
#  define PTRNULL "(nil)"
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
# endif

int	ft_printf(const char *format, ...);
int	ft_handle_format(const char c, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n, int base, char spec);
int	ft_putptr(void *ptr);

#endif