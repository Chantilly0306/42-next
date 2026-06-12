/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:07:13 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/10 17:27:52 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	index_hay;
	size_t	len_needle;

	if (!needle)
		return ((char *)haystack);
	index_hay = 0;
	len_needle = ft_strlen(needle);
	while (haystack[index_hay] && index_hay + len_needle <= len)
	{
		i = 0;
		if (haystack[index_hay] == needle[i])
		{
			while (needle[i])
			{
				if (haystack[index_hay + i] != needle[i])
					break ;
				i++;
				if (i == len_needle)
					return ((char *)haystack + index_hay);
			}
		}
		index_hay++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*res;

	res = ft_strnstr("Hello World WORLD", "WORLD", 17);
	if (res)
		printf("%s\n", res);
	else
		printf("NULL\n");
}
*/