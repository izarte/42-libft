#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"

void	test(const char *str, const char *str2, int n)
{
	int	ori = strncmp(str, str2, n);
	int	own = ft_strncmp(str, str2, n);
	if (ori != own)
		printf("ERROR in test %s %s %i:\noriginial: %i own: %i\n", str, str2, n, ori, own);
}

int main(void)
{
	test("Strings are the same", "Strings are the same", strlen("Strings are the same"));
	test("Strings are not the same", "Strings are the same", strlen("Strings are the same"));
	test("Empty string", "", 3);
	test("", "Empty string", 1);
	test("", "", 5);
	test("test", "testtest", strlen("test"));
	printf("Test ft_strncmp completed!\n");
}
