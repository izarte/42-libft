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
		return (ft_lstlast_bonus(lst->next));
	return (lst);
}

void test(t_list *lst)
{
    t_list *ori = lstlast(lst);
    t_list *own = ft_lstlast_bonus(lst);
	if ((ori && own) && (ori->content != 0 && own->content != 0) && (ori->content != own->content || (own->next)))
		printf("ERROR in l1:%s l2:%s\n", (char *)ori->content, (char *)own->content);
}


int main()
{
    t_list *t;
	t = 0;
	test(t);
    t = ft_lstnew_bonus("test");
	test(t);
	ft_lstadd_front_bonus(&t, ft_lstnew_bonus("new"));
	ft_lstadd_front_bonus(&t, ft_lstnew_bonus("3"));
	test(t);
	ft_lstadd_front_bonus(&t, ft_lstnew_bonus("test"));
	ft_lstadd_front_bonus(&t, ft_lstnew_bonus("18"));
	ft_lstadd_front_bonus(&t, ft_lstnew_bonus("new"));
	ft_lstadd_front_bonus(&t, ft_lstnew_bonus(""));
	test(t);
	printf("Test ft_lstlast_bonus completed!\n");
    return 0;
}