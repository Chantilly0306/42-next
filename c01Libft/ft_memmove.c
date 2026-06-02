/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:20:39 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/02 16:22:56 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, int n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
		while (--n >= 0)
			d[n] = s[n];
	else
		while (i++ < n)
			d[i] = s[i];
	return (dst);
}
/*
int	main(void)
{
	char	str1[] = "ABCDEF";
	char	*str2;

	str2 = str1 + 2;
	ft_memmove(str1, str2, 3);
	printf("%s\n", str1);
	//printf("%ld\n", str1 - str2);
}
*/
