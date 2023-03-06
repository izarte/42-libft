/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:45:57 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 02:44:31 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *str, int c, size_t n)
{
	unsigned char	*uc_str;
	unsigned char	uc;
	size_t			i;

	uc_str = (unsigned char *)str;
	uc = (char)c;
	i = 0;
	while (i < n)
	{
		if (uc_str[i] == uc)
			return (uc_str + i);
		i++;
	}
	return (0);
}
