#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"

void	test(void *str, void *str2, int c, size_t n)
{
	char	*ori = memset(str, c, n);
	char	*own = (char *)ft_memset(str2, c, n);
	if (strcmp(ori, own))
		printf("ERROR in test %s %c %li:\noriginial: %s own: %s\n", (char *)str, c, n, ori, own);
}

int main(void)
{
	char buff1[128] = "Default string to overwrite on it";
	char buff2[128] = "Default string to overwrite on it";
	test(buff1, buff2, 'I', 18);
	test(buff1, buff2, 'Z', 18);
	test(buff1, buff2, 'R', 18);
	printf("Test ft_memset completed!\n");
}
