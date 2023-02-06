/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:03:57 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/06 15:11:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		found;
	char	*big_ptr;
	char	*lit_ptr;

	found = 0;
	big_ptr = (char *) big;
	if (!*little)
		return (big_ptr);
	while (!found && *big_ptr)
	{
		lit_ptr = (char *)little;
		i = 0;
		while (big_ptr[i] == lit_ptr[i] && lit_ptr[i])
			i++;
		if (lit_ptr[i] == '\0')
			found = 1;
		else
			big_ptr++;
	}
	if (!found)
		big_ptr = 0;
	return (big_ptr);
}
