#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	test(const char *str)
{
    char *ori = strdup(str);
	char *own = ft_strdup(str);
	if (strcmp(ori, own))
		printf("ERROR in test %s:\noriginial: %s own: %s\n", str, ori, own);
}

int main(void)
{
	test("Test");
	test("");
	test("String to be duplicated");
	printf("Test ft_strdup completed!\n");
}
