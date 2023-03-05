/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:09:11 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/07 15:09:11 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	dst_size = (size_t)ft_strlen(dst);
	src_size = (size_t)ft_strlen((char *)src);
	i = 0;
	while (size && dst_size + i < size - 1 && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	if (size != 0)
		dst[dst_size + i] = '\0';
	if (src_size + size < src_size + dst_size)
		return (src_size + size);
	return (src_size + dst_size);
	return ((size_t)ft_strlen(dst));
}
