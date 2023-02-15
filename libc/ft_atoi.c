/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:16:09 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/06 15:16:09 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result + *str - '0';
		str++;
	}
	result = sign * result;
	return (result);
}
