/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:44:58 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 01:08:03 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
static int	count_words(char *s, char c);
static char	*string_to_separator(char **s, char c);
static int	count_to_separator(char *s, char c);
static void	free_string(char **s);

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*str;
	int		i;
	int		words;

	str = (char *) s;
	words = count_words(str, c);
	out = (char **) malloc((words + 1) * sizeof(char *));
	if (!out)
		return (0);
	out[words] = 0;
	i = 0;
	while (i < words)
	{
		while (*str == '\0' || *str == c)
			str++;
		out[i] = string_to_separator(&str, c);
		if (!out[i])
		{
			free_string(out);
			return (0);
		}
		i++;
	}
	return (out);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == '\0' || s[i + 1] == c)
			&& (s[i] != '\0' && s[i] != c))
			words++;
		i++;
	}
	return (words);
}

static char	*string_to_separator(char **s, char c)
{
	char	*out;
	int		size;

	size = count_to_separator(*s, c);
	out = ft_substr((const char *) *s, 0, size);
	*s = *s + size + 1;
	return (out);
}

static int	count_to_separator(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_string(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return ;
}
