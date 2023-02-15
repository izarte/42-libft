/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:06:24 by izarate-          #+#    #+#             */
/*   Updated: 2023/02/15 14:37:45 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void    *ft_calloc(size_t n, size_t size)
{
    unsigned char   *ptr;

    ptr = malloc(n * size);
    if (!ptr)
        return (0);
    while (n--)
    {
        *ptr = 0;
        ptr++;
    }
    return (ptr);
}
