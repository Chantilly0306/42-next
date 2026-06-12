/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:05:46 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/12 17:57:25 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libt.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst || !del)
		return ;
	buf = *lst;
	while (*lst)
	{
		buf = *lst;
		*lst = (*lst)->next;
		del(buf->content);
		free(buf);
	}
}
