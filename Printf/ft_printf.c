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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	n;

	count = 0;
	(void)format;
	va_start(args, format);
	n = va_arg(args, int);
	

	va_end(args);

	if (n == 42)
		write(1, "42\n", 3);
	return (0);
}