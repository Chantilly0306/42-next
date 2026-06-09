/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:07:13 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/09 17:20:44 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	while (i < len && i + len_needle <= len)
	{
		j = 0;
		if (haystack[i] = needle[j])
		{
			while (needle[j])
			{
				if (haystack[i] != needle[i])
					break ;
				i++;
				j++;
			}
		}
		i++;
	}
}
