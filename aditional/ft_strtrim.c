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

// TODO: REVIEW IF SPACE IS A CHARACTER

int			ft_strlen(char *str);
static int	count_appear(char *s1, char const *set);
static int	is_in(char s1, char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		rm_count;
	char	*s1_mdfy;
	char	*out;

	s1_mdfy = (char *) s1;
	rm_count = count_appear(s1_mdfy, set);
	out = (char *) malloc((ft_strlen(s1_mdfy) - rm_count) * sizeof(char));
	i = 0;
	while (*s1_mdfy)
	{
		if (!is_in(*s1_mdfy, (char *) set))
		{
			out[i] = *s1_mdfy;
			i++;
		}
		s1_mdfy++;
	}
	return (out);
}

static int	count_appear(char *s1, char const *set)
{
	int		i;

	i = 0;
	while (*s1)
	{
		if (is_in(*s1, (char *) set))
			i++;
		s1++;
	}
	return (i);
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
