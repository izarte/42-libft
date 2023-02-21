#include <stdio.h>

#include "../../libft.h"

void test(const char *s, char c)
{
	char **own = ft_split(s, c);
	// while (*own)
	// {
	// 	printf("%s\n", *own);
	// 	*own = *own + 1;
	// }
	// if (strcmp(own, str))
		// printf("ERROR in test %i :\noriginial: %s own: %s\n", n, str, own);
}

int main()
{
	test("test", 'z');
	printf("Test ft_split completed!\n");
}