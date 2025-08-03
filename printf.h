/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:49:46 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/03 17:37:22 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
//for uintmax_t && intmax_t
#include <unistd.h>
//for write


# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define NPTRSIZE 5
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# endif

