#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../libft.h"

void	test(const void *str, const void *str2, int n)
{
	int	ori = memcmp(str, str2, n);
	int	own = ft_memcmp(str, str2, n);
	if (ori != own)
		printf("ERROR in test %s %s %i:\noriginial: %i own: %i\n", (char *)str, (char *)str2, n, ori, own);
}

int main(void)
{
	test("Strings are the same", "Strings are the same", strlen("Strings are the same"));
	test("Strings are not the same", "Strings are the same", strlen("Strings are the same"));
	test("Empty string", "", 1);
	test("", "Empty string", 1);
	test("", "", 5);
	test("test", "testtest", strlen("test"));
	printf("Test ft_memcmp completed!\n");
}
