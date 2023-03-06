#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

void	lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast_bonus(*lst)->next = new;
}

void	print_list(t_list *list)
{
	printf("List:\n");
	while (list != NULL)
	{
		if (list->content != NULL)
			printf("%s\n", (char *)list->content);
		else
			printf("NULL\n");
		list = list->next;
	}
}

int compare_lists(t_list *l1, t_list *l2)
{
    while (l1 && l2)
    {
        if (l1->content != l2->content)
            printf("ERROR in l1:%s l2:%s\n", (char *)l1->content, (char *)l2->content);
        l1 = l1->next;
        l2 = l2->next;
    }
    if ((!l1 && l2) || (l1 && !l2))
        printf("ERROR in l2:%s\n", (char *)l2->content);
    if ((l1 && !l2))
        printf("ERROR in l1:%s\n", (char *)l1->content);
    return 1;
}

void test(t_list **lst, t_list **lst2, t_list *new)
{
    lstadd_back(lst, new);
    ft_lstadd_back_bonus(lst2, new);
    compare_lists(*lst, *lst2);
}


int main()
{
    t_list *t;
    t_list *t2;
    t = 0;
    t2 = 0;
    test(&t, &t2, ft_lstnew_bonus("first"));
    t = ft_lstnew_bonus("test");
    t2 = ft_lstnew_bonus("test");
    lstadd_back(&t, ft_lstnew_bonus("new"));
    lstadd_back(&t, ft_lstnew_bonus("new"));
    lstadd_back(&t, ft_lstnew_bonus("new"));
    lstadd_back(&t, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    test(&t, &t2, ft_lstnew_bonus("last"));
    printf("Test ft_lstadd_back_bonus completed!\n");
    return 0;
}