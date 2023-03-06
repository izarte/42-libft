/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:56:52 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/20 19:56:52 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen(const char *s);
static int	is_in(char s1, char *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	size;

	if (s1 == NULL || set == NULL)
		return ((char *) s1);
	start = 0;
	size = ft_strlen(s1);
	while (start < size && is_in(s1[start], (char *) set))
		start++;
	while (start < size && is_in(s1[size - 1], (char *) set))
		size--;
	return (ft_substr(s1, start, size - start));
}

static int	is_in(char s1, char *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}
