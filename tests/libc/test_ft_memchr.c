#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../../libft.h"

void	test(void *str, char c, size_t n)
{
	char str2[128];
	strcpy(str2, str);
	char *ori = memchr(str, c, n);
	char *own = (char *)ft_memchr(str2, c, n);
	if ((ori && own) || (!ori && !own))
		return;
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %p %c:\noriginial: %s own: %s\n", str, c, ori, own);
}


int main(void)
{
	test("First string", 't', 5);
	test("Second string", 's', 10);
	test("NOT YES", ' ', 3);
	test("NOT YES", ' ', 4);
	test("NOT YES", ' ', 5);
	test("Multiple u in string", 'u', 13);
	test("Not found", 'z', 12);
	test("LAST TEST in test", 'e', 1);
	test("", '-', 2);
	printf("Test ft_memchr completed!\n");
}
