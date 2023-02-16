#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../../libft.h"

void	test(size_t n, size_t size)
{
	unsigned char *ori = (unsigned char *)calloc(n, size);
	unsigned char *own = (unsigned char *)ft_calloc(n, size);
	if (strcmp((const char *)ori, (const char *)own))
		printf("ERROR in test %li %li:\noriginial: %s own: %s\n", n, size, ori, own);
}

int main(void)
{
	test(18, sizeof(char));
	test(18, sizeof(int));
	test(18, sizeof(long));
	test(0, sizeof(unsigned char));
	printf("Test ft_calloc completed!\n");
}
