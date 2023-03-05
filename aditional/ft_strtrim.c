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

int			ft_strlen(char *str);
static int	is_in(char s1, char *set);
char		*ft_strdup(const char *str);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*s1_mdfy;
	char	*out;

	if (!s1 || !set)
		return (0);
	s1_mdfy = (char *) s1;
	while (is_in(*s1_mdfy, (char *) set))
		s1_mdfy++;
	size = ft_strlen(s1_mdfy) - 1;
	while (is_in(s1_mdfy[size], (char *) set))
	{
		s1_mdfy[size] = '\0';
		size--;
	}
	out = ft_strdup(s1_mdfy);
	return (out);
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
