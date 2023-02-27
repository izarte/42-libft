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

int	ft_strlen(char *str);

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*ptr;

	size = ft_strlen((char *)str);
	ptr = (char *)malloc(size * sizeof(char));
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
