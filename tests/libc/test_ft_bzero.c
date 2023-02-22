#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"

void	test(void *str, void *str2, size_t n)
{
	bzero(str, n);
	ft_bzero(str2, n);
	if (strcmp(str, str2))
		printf("ERROR in test %s %li:\noriginial: %s own: %s\n", (char *)str, n, (char *)str, (char *)str2);
}

int main(void)
{
	char buff1[128] = "Default string to overwrite on it";
	char buff2[128] = "Default string to overwrite on it";
	test(buff1, buff2, 18);
	test(buff1, buff2, 1);
	test(buff1, buff2, 0);
	test(buff1, buff2, 3);
	printf("Test ft_bzero completed!\n");
}
