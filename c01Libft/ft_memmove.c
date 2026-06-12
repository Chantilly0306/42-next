/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:20:39 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/09 13:28:50 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	str1[] = "ABCDEF";
	char	*str2; // CDEF

	str2 = str1 + 2;
	ft_memmove(str2, str1, 3);
	printf("%s\n", str2); //ABCF
	printf("%p\n", (void *)str1);
	printf("%p\n", (void *)str2);
	printf("%ld\n", str2 - str1);
}
*/