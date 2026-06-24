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

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	print_nbr(int nbr)
{
	int		len;
	char	c;

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += print_nbr(nbr / 10);
	c = '0' + nbr % 10;
	len += write(1, &c, 1);
	return (len);
}

int	print_unsigned_int(unsigned int nbr)
{
	int		len;
	char	c;

	len = 0;
	if (nbr >= 10)
		len += print_unsigned_int(nbr / 10);
	c = '0' + nbr % 10;
	len += write(1, &c, 1);
	return (len);
}

int	print_hex(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += print_hex(nbr / 16, base);
	len += write(1, &base[nbr % 16], 1);
	return (len);
}

int	print_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = 2;
	len += print_hex((unsigned long)ptr, "0123456789abcdef");
	return (len);
}

int	parse_conversion(char format, va_list *args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += print_char(va_arg(*args, int));
	else if (format == 's')
		len += print_str(va_arg(*args, char *));
	else if (format == 'p')
		len += print_ptr(va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		len += print_nbr(va_arg(*args, int));
	else if (format == 'u')
		len += print_unsigned_int(va_arg(*args, unsigned int));
	else if (format == 'x')
		len += print_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
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
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'
			|| format[i + 1] == 'p' || format[i + 1] == 'd'
			|| format[i + 1] == 'i' || format[i + 1] == 'u'
			|| format[i + 1] == 'x' || format[i + 1] == 'X'
			|| format[i + 1] == '%'))
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
	va_end(args);
	return (total_len);
}

int	main(void)
{
	int		n = 42;
	char	c = 't';
	char	*s = "Nex";
	// int		len;
	// len = ft_printf("%d%c%\n", n, c);
	// ft_printf("%i\n", len);
	printf("Hi! %%%d %s%c\n", n, s, c);
	ft_printf("Hi! %%%d %s%c\n", n, s, c);
	// printf("%p\n", &n);
	// ft_printf("%p\n", &n);
	// char	*nu = NULL;
	// int	i;
	// i = ft_printf("%s", nu);
	// ft_printf("%p\n", &i);
	// ft_printf("%i\n", i);
}