#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

// TODO: CHECK MEMORY LEAKS

// t_list	*lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new;
// 	t_list	*tmp;

// 	if (lst == NULL || f == NULL)
// 		return (NULL);
// 	new = NULL;
// 	while (lst != NULL)
// 	{
// 		tmp = ft_lstnew_bonus(f(lst->content));
// 		if (tmp == NULL)
// 		{
// 			ft_lstclear_bonus(&new, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back_bonus(&new, tmp);
// 		lst = lst->next;
// 	}
//     return (new);
// }

// void    a(void *s)
// {
//     if (!s)
//         s = "test";
// }

// void    del1(void *s)
// {
//     if (!s)
//         s = 0;
// }

// int compare_lists(t_list *l1, t_list *l2)
// {
//     while (l1 && l2 && l1->content && l2->content)
//     {
//         if (l1->content != l2->content)
//             printf("ERROR in l1:%s l2:%s\n", (char *)l1->content, (char *)l2->content);
//         l1 = l1->next;
//         l2 = l2->next;
//     }
//     if ((!l1 && l2))
//         printf("ERROR in l2:%s\n", (char *)l2->content);
//     if ((l1 && !l2))
//         printf("ERROR in l1:%s\n", (char *)l1->content);
//     return 1;
// }

// void test(t_list *lst, t_list *lst2)
// {
//     void *(*p)(void *);
//     p = (void * (*)(void *))&a;
//     // b = &p;
// 	// void	*ff = &f;
//     t_list *ori = lstmap(lst, p, &del1);
//     t_list *own = ft_lstmap_bonus(lst2, p, &del1);
//     compare_lists(ori, own);
// }

int main()
{
    // t_list *t;
    // t_list *t2;
    // t = 0;
    // t2 = 0;
    // test(t, t2);
    // t = ft_lstnew_bonus("test");
    // t2 = ft_lstnew_bonus("test");
    // ft_lstadd_back_bonus(&t, ft_lstnew_bonus("new"));
    // ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    // ft_lstadd_back_bonus(&t, ft_lstnew_bonus("new"));
    // ft_lstadd_back_bonus(&t2, ft_lstnew_bonus("new"));
    // test(t, t2);
    printf("Test ft_lstmap_bonus completed!\n");
    return 0;
}