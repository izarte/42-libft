/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:58:31 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/06 02:23:07 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

char	*ft_strrchr(const char *str, int c)
{
	char	*str_out;
	int		i;
	char	cc;

	cc = (char) c;
	str_out = (char *)str;
	i = ft_strlen(str_out);
	while (i > 0 && str[i] != cc)
		i--;
	str_out = (char *)str + i;
	if (*str_out != cc)
		return (0);
	return (str_out);
}
