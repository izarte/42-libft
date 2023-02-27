/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:50:54 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/24 19:05:54 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;

	if (!lst || !f)
		return (0);
	out = 0;
	while (lst)
	{
		ft_lstadd_back(&out, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(out))
		{
			ft_lstclear(&out, del);
			return (0);
		}
		lst = lst->next;
	}
	return (out);
}
