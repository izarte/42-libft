/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:03:57 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/14 17:03:07 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	char	*big_ptr;
	char	*lit_ptr;

	if (n == 0  && !big)
		return (0);
	big_ptr = (char *) big;
	if (!*little)
		return (big_ptr);
	if (big == little)
		return ((char *) big);
	i = 0;
	while (big_ptr[i] && i < n)
	{
		lit_ptr = (char *)little;
		j = 0;
		while (big_ptr[i + j] == lit_ptr[j] && lit_ptr[j] && (i + j) < n)
		{
			if (lit_ptr[j + 1] == '\0')
				return (&big_ptr[i]);
			j++;
		}
		i++;
	}
	return (0);
}
