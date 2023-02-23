#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

t_list	*lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	return (lst);
}

void test(t_list *lst)
{
    t_list *ori = lstlast(lst);
    t_list *own = ft_lstlast(lst);
	if ((ori && own) && (ori->content != 0 && own->content != 0) && (ori->content != own->content || (own->next)))
		printf("ERROR in l1:%s l2:%s\n", (char *)ori->content, (char *)own->content);
}


int main()
{
    t_list *t;
	t = 0;
	test(t);
    t = ft_lstnew("test");
	test(t);
	ft_lstadd_front(&t, ft_lstnew("new"));
	ft_lstadd_front(&t, ft_lstnew("3"));
	test(t);
	ft_lstadd_front(&t, ft_lstnew("test"));
	ft_lstadd_front(&t, ft_lstnew("18"));
	ft_lstadd_front(&t, ft_lstnew("new"));
	ft_lstadd_front(&t, ft_lstnew(""));
	test(t);
	printf("Test ft_lstlast completed!\n");
    return 0;
}