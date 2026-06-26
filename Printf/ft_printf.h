/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 11:09:45 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/14 11:22:16 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	parse_conversion(char format, va_list *args);
int	is_conversion(char c);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nbr);
int	ft_print_unsigned_int(unsigned int nbr);
int	ft_print_hex(unsigned long nbr, char *base);
int	ft_print_ptr(void *ptr);

#endif
