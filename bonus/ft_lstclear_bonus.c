/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:03:25 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 02:03:25 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_bonus(t_list *lst, void (*del)(void *));

void	ft_lstclear_bonus(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*actual;

	if (!lst || !del)
		return ;
	if (!(*lst))
		return ;
	actual = *lst;
	while (*lst)
	{	
		tmp = (*lst)->next;
		ft_lstdelone_bonus(*lst, del);
		*lst = tmp;
	}
	*lst = actual;
	*lst = 0;
}
