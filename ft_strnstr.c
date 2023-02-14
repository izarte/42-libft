/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:03:57 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/14 17:00:21 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// char	*ft_strnstr(const char *big, const char *little, size_t n)
// {
// 	int		i;
// 	int		found;
// 	char	*big_ptr;
// 	char	*lit_ptr;

// 	found = 0;
// 	big_ptr = (char *) big;
// 	if (!*little)
// 		return (big_ptr);
// 	while (n-- > 1 && !found && *big_ptr)
// 	{
// 		lit_ptr = (char *)little;
// 		i = 0;
// 		while (big_ptr[i] == lit_ptr[i] && lit_ptr[i])
// 			i++;
// 		if (lit_ptr[i] == '\0')
// 			found = 1;
// 		else
// 			big_ptr++;
// 	}
// 	if (!found)
// 		big_ptr = 0;
// 	return (big_ptr);
// }

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *) str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == *needle)
		{
			j = 0;
			while (needle[j] && str[i + j] && i + j < len)
			{
				if (str[i + j] != needle[j])
					break ;
				j++;
			}
			if (!needle[j])
				return ((char *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
