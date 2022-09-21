/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:58:31 by izarate-          #+#    #+#             */
/*   Updated: 2022/09/22 01:18:40 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*str_out;

	str_out = 0;
	while(*str)
	{
		if (*str == c)
			str_out = (char *)str;
		str++;
	}
	return (str_out);
}
