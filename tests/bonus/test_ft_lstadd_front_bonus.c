#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

void	lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
    lstadd_front(lst, new);
    ft_lstadd_front_bonus(lst2, new);
    compare_lists(*lst, *lst2);
}


int main()
{
    t_list *t;
    t_list *t2;
    t = ft_lstnew_bonus("test");
    t2 = ft_lstnew_bonus("test");
    test(&t, &t2, ft_lstnew_bonus("new"));
    test(&t, &t2, ft_lstnew_bonus("test2"));
    test(&t, &t2, ft_lstnew_bonus("new2"));
    printf("Test ft_lstadd_front_bonus completed!\n");
    return 0;
}