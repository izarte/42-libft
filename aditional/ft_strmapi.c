/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:53:43 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/21 13:53:43 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*out;
	char	*str;

	str = (char *) s;
	size = ft_strlen(str);
	out = (char *) malloc((size + 1) * sizeof(char));
	if (!out)
		return (0);
	out[size] = 0;
	size--;
	while (size >= 0)
	{
		out[size] = f((unsigned int)size, str[size]);
		size--;
	}
	return (out);
}
