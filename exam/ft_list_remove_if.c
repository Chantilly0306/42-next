#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list  *cursor;
    t_list  *tmp;

    if (!begin_list || !cmp)
        return ;
    cursor = *begin_list;
    while (cursor && !cmp(cursor->data, data_ref))
    {
        *begin_list = cursor->next;
        free(cursor);
        cursor = *begin_list;
    }
    while (cursor && cursor->next)
    {
        if (!cmp(cursor->next->data, data_ref))
        {
            tmp = cursor->next;
            cursor->next = tmp->next;
            free(cursor->next);
        }
        else
            cursor->next;
    }
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*cursor;
	t_list	*prev;

	if (!begin_list || !cmp)
		return ;
	cursor = *begin_list;
	while (cursor)
	{
		if (cursor == *begin_list && !cmp(cursor->data, data_ref))
		{
			*begin_list = cursor->next;
			free(cursor);
			cursor = *begin_list;
		}
		else if (!cmp(cursor->data, data_ref))
		{
			prev->next = cursor->next;
			free(cursor);
			cursor = prev->next;
		}
		else
		{
			prev = cursor;
			cursor = cursor->next;
		}
	}
}

#include <stdio.h>

t_list  *ft_create_elem(void *data)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (0);
    node->next = NULL;
    node->data = data;
    return (node);
}

int cmp(void *data1, void *data2)
{
    int     i = 0;
    char    *str1;
    char    *str2;

    str1 = (char *)data1;
    str2 = (char *)data2;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (str1[i] - str2[i]);
}

int main(void)
{
    int     i = 0;
    char    *strs[] = {"abc", "ab", "abc", "abcde", "abc", "abc", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    printf("%p\n", new_list);
    printf("%s\n", (char *)(new_list->data));
    ft_list_remove_if(&new_list, "abc", cmp);
    printf("%p\n", new_list);
    printf("%s\n", (char *)(new_list->data));
    printf("%s\n", (char *)(new_list->next->data));
}
