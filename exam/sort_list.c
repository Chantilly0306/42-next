#include "list.h"

// bubble sort
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*current;
	int		tmp;

	current = lst
	while (current && current->next)
	{
		if (!cmp(current->data, current->next->data))
		{
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
			current = lst;
		}
		else
			current = current->next;
	}
	return (lst);
}
