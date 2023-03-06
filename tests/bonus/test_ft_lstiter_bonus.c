#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

// TODO: CHECK MEMORY LEAKS

void	lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	if (lst->content != NULL)
		f(lst->content);
	if (lst->next != NULL)
		lstiter(lst->next, f);
}

void    f(void *s)
{
    if (!s)
        s = "test";
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

void test(t_list *lst, t_list *lst2)
{
    lstiter(lst, &f);
    ft_lstiter_bonus(lst2, &f);
    compare_lists(lst, lst2);
}

int main()
{
    t_list *t;
    t_list *t2;
    t = 0;
    t2 = 0;
    test(t, t2);
    t = ft_lstnew_bonus("test");
    t2 = ft_lstnew_bonus("test");
    ft_lstadd_back_bonus(&t, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t, ft_lstnew_bonus("new"));
    ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    test(t, t2);
    printf("Test ft_lstiter_bonus completed!\n");
    return 0;
}