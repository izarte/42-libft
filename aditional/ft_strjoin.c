/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:22:02 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/20 19:22:02 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size;
	int		i;
	char	*out;

	size1 = ft_strlen((char *) s1);
	size = ft_strlen((char *) s2);
	size += size1;
	out = (char *) malloc((size + 1) * sizeof(char));
	if (!out)
		return (0);
	i = 0;
	while (i < size)
	{
		if (i < size1)
			out[i] = s1[i];
		else
			out[i] = s2[i - size1];
		i++;
	}
	out[i] = '\0';
	return (out);
}
