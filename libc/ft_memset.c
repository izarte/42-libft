/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:28:35 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/14 15:50:55 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*uc_str;

	uc_str = str;
	while (n)
	{
		*uc_str = (unsigned char)c;
		n--;
		uc_str++;
	}
	return (str);
}
