#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

void    del(void *s)
{
    if (!s)
        s = 0;
}

void test(t_list *lst)
{
    ft_lstdelone(lst, &del);
    if (lst && lst->content)
        printf("ERROR\n");
}

int main()
{
    t_list *t;
    t = 0;
    test(t);
    t = ft_lstnew("test");
    test(t);
    printf("Test ft_lstdelone completed!\n");
    return 0;
}