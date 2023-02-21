/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:18:15 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/21 19:18:15 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

void	ft_putstr_fd(char *str, int fd)
{
	int	size;

	if (!str)
		return ;
	size = ft_strlen(str);
	write(fd, str, size);
}
