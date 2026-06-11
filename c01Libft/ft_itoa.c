/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:49:55 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/11 19:38:37 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(long nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
		size = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		size;
	char	*str;

	nb = (long)n;
	size = get_size(nb);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		return ("0");
	str[size] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--size] = '0' + nb % 10;
		nb /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
}
*/
