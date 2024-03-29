/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:57:30 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/21 12:57:30 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_digits(int n);
static char	*get_array(char *out, int size, int n, int i);

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*out;

	size = count_digits(n);
	out = (char *) malloc((size + 1) * sizeof(char));
	if (!out)
		return (0);
	out[size] = '\0';
	i = 0;
	if (n == 0)
		out[0] = '0';
	if (n < 0)
	{
		out[i] = '-';
		out[size - 1] = -(n % 10) + '0';
		n /= 10;
		n = n * -1;
		i++;
	}
	out = get_array(out, size, n, i);
	return (out);
}

static int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i = 2;
		n /= 10;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*get_array(char *out, int size, int n, int i)
{
	while (n)
	{
		out[size - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (out);
}
