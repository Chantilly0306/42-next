/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:32:27 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/09 16:33:52 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
/*
int main()
{
    char *s1 = "Hello, World!";
    char *s2 = "Hello, 42!";
    
    printf("%d\n", ft_strncmp(s1, s2, 8));
}
*/
