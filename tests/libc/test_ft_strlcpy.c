#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"

size_t	ori_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;

	i = 0;
	dst_l = strlen(src);
	if (size == 0)
		return (dst_l);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst_l);
}


void	test(const char *str, int n)
{
	char buff[128] = "Overwrite here";
	char buff2[128] = "Overwrite here";
	int ori = ori_strlcpy(buff, str, n);
	int own = ft_strlcpy(buff2, str, n);
	if (ori != own || strcmp(buff, buff2))
		printf("ERROR in test %s:\noriginial: %s %i own: %s %i\n", str, buff, ori, buff2, own);
}


int main(void)
{
	test("here", 4);
	test("here", 3);
	test("here", 1);
	test("", 1);
	printf("Test ft_strlcpy completed!\n");
}
