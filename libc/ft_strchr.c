/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:50:13 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 02:22:34 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	char	cc;

	cc = (char)c;
	if (!str)
		return (0);
	s = (char *)str;
	while (*s && *s != cc)
		s++;
	if (*s != cc)
		return (0);
	return (s);
}
