/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:28:03 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/27 16:56:33 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strdup(const char *str)
{
	int		size;
	char	*ptr;

	size = ft_strlen((char *)str);
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, str, size + 1);
	return (ptr);
}
