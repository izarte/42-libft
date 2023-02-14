/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:58:31 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/14 15:10:38 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

char	*ft_strrchr(const char *str, int c)
{
	char	*str_out;
	int		i;

	str_out = (char *)str;
	i  = ft_strlen(str_out);
	while (i > 0 && str[i] != c)
		i--;
	str_out = (char *)str + i;
	if (*str_out != c)
		return (0);
	return (str_out);
}
