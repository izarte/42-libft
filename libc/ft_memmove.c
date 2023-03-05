/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:03:55 by izarate-          #+#    #+#             */
/*   Updated: 2022/09/26 12:06:52 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;

	uc_dst = (unsigned char *) dst;
	uc_src = (const unsigned char *) src;
	if (!uc_dst && !uc_src)
		return (0);
	if (uc_src < uc_dst && uc_dst < uc_src + n)
		while (n--)
			*(uc_dst + n) = *(uc_src + n);
	else
		while (n--)
			*uc_dst++ = *uc_src++;
	return (dst);
}
