/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:08:34 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/14 16:27:07 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*uc_str1;
	const unsigned char	*uc_str2;
	size_t				i;

	uc_str1 = str1;
	uc_str2 = str2;
	i = 0;
	while (i < n)
	{
		if (uc_str1[i] != uc_str2[i])
			return (uc_str1[i] - uc_str2[i]);
		i++;
	}
	return (0);
}
