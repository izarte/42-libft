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

int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	out;

	dst_size = ft_strlen(dst);
	if (dst_size > size)
		dst_size = size;
	out = ft_strlcpy(&(dst[dst_size]), src, size - dst_size);
	return (out + dst_size);
}
