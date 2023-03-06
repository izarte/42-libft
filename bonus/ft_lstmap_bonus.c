/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:02:48 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 02:02:49 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_bonus(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;

	if (!lst || !f)
		return (0);
	out = 0;
	while (lst)
	{
		ft_lstadd_back_bonus(&out, ft_lstnew_bonus(f(lst->content)));
		if (!ft_lstlast_bonus(out))
		{
			ft_lstclear_bonus(&out, del);
			return (0);
		}
		lst = lst->next;
	}
	return (out);
}
