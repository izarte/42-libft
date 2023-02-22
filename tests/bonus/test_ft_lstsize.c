#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

int	lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (1);
	return (1 + ft_lstsize(lst->next));
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

void test(t_list *lst, int n)
{
    int ori = lstsize(lst);
    int own = ft_lstsize(lst);
	if (ori != own)
		printf("ERROR in test %i :\noriginial: %i own: %i\n", n, ori, own);
}


int main()
{
    t_list *t;
	t = 0;
	test(t, 1);
    t = ft_lstnew("test");
	test(t, 2);
	ft_lstadd_front(&t, ft_lstnew("new"));
	ft_lstadd_front(&t, ft_lstnew("3"));
	test(t, 3);
	ft_lstadd_front(&t, ft_lstnew("test"));
	ft_lstadd_front(&t, ft_lstnew("18"));
	ft_lstadd_front(&t, ft_lstnew("new"));
	ft_lstadd_front(&t, ft_lstnew(""));
	test(t, 4);
    printf("Test ft_lstsize completed!\n");
    return 0;
}