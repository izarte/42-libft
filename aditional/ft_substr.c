/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:45:31 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 03:10:35 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > (unsigned int)size || len == 0)
	{
		ptr = (char *) malloc(sizeof(char));
		if (!ptr)
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > size - start)
		len = size - start;
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &(s[start]), len + 1);
	return (ptr);
}
