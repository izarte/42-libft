/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:45:57 by izarate-          #+#    #+#             */
/*   Updated: 2022/09/23 09:52:16 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *str, int c, size_t n)
{
	unsigned char	*uc_str;
	unsigned char	uc;

	uc_str = str;
	uc = (char)c;
	while (n && *uc_str != uc)
	{
		n--;
		uc_str++;
	}
	str = uc_str;
	return (str);
}
