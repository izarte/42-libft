#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

t_list	*lstnew(void *content)
{
	t_list	*e;

	e = malloc(sizeof(t_list));
	if (e == NULL)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
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

void test(void *a)
{
    t_list *ori = lstnew(a);
    t_list *own = ft_lstnew(a);
    compare_lists(ori, own);

}


int main()
{
    int a = 3;
    char b = 18;
    char c[] = "test";
    test(&a);
    test(&b);
    test(c);
    printf("Test ft_lstnew completed!\n");
    return 0;
}