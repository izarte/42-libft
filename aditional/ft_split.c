/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:44:58 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/21 22:28:51 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_separators(char *s, char c);
static char	*string_to_separator(char **s, char c);
static int	count_to_separator(char *s, char c);
static void	free_string(char **s);

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*str;
	int		i;

	str = (char *) s;
	out = (char **) malloc(count_separators(str, c) * sizeof(char *));
	i = 0;
	while (*str)
	{
		out[i] = string_to_separator(&str, c);
		if (!out[i])
		{
			free_string(out);
			return (0);
		}
		i++;
	}
	out[i] = 0;
	return (out);
}

static int	count_separators(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i + 1);
}

static char	*string_to_separator(char **s, char c)
{
	char	*out;
	int		i;

	out = (char *) malloc(count_to_separator(*s, c) * sizeof(char));
	i = 0;
	while (**s != c && **s)
	{
		out[i] = **s;
		*s = *s + 1;
		i++;
	}
	if (**s)
		*s = *s + 1;
	return (out);
}

static int	count_to_separator(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	free_string(char **s)
{
	int	i;

	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return ;
}
