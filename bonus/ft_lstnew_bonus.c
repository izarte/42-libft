/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:02:39 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 02:02:41 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew_bonus(void *content)
{
	t_list	*list;

	list = malloc(sizeof(*content));
	if (!list)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}
