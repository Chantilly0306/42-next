/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:58 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/09 15:53:40 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	s += len;
	if ((char)c == '\0')
		return ((char *)s);
	while (len-- > 0)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
/*
int main()
{
    char *str = "Hello, World!";
    char c = 'o';
    char *result = ft_strrchr(str, c);

    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Not found\n");
    return 0;
}
*/