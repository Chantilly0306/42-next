/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 11:14:51 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/14 11:15:29 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	parse_conversion(char format, va_list *args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		len += ft_print_unsigned_int(va_arg(*args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

int	is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	total_len;

	if (!format)
		return (-1);
	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_conversion(format[i + 1]))
		{
			i++;
			total_len += parse_conversion(format[i], &args);
		}
		else
		{
			write(1, &format[i], 1);
			total_len++;
		}
		i++;
	}
	return (va_end(args), total_len);
}
/*
int	main(void)
{
	int		len;
	int		n = -42;
	char	c = 't';
	char	*s = "Nex";
	char	*nu = NULL;

	len = ft_printf("Hi! %%%d %s%c", n, s, c);
	ft_printf("\ntotal length = %i\n\n", len);
	len = ft_printf("%p", ft_printf);
	ft_printf("\ntotal length = %i\n\n", len);
	len = ft_printf("%p", nu);
	ft_printf("\ntotal length = %i\n", len);
}
*/