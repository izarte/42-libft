#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

// TODO: CHECK MEMORY LEAKS

void	lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || *lst == NULL)
		return ;
	lstclear(&(*lst)->next, del);
	ft_lstdelone_bonus(*lst, del);
	*lst = NULL;
}

void    del(void *s)
{
    if (!s)
        s = 0;
}

int compare_lists(t_list *l1, t_list *l2)
{
    while (l1 && l2 && l1->content && l2->content)
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

void test(t_list **lst, t_list **lst2)
{
    lstclear(lst, &del);
    ft_lstclear_bonus(lst2, &del);
    compare_lists(*lst, *lst2);
}

int main()
{
    t_list *t;
    t_list *t2;
    t = 0;
    t2 = 0;
    test(&t, &t2);
    t = ft_lstnew_bonus("test");
    t2 = ft_lstnew_bonus("test");
    ft_lstadd_back_bonus(&t, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    test(&t, &t2);
    printf("Test ft_lstclear_bonus completed!\n");
    return 0;
}