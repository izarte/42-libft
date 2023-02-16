#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../../libft.h"

void	test(const char *str, char c)
{
	char *ori = strchr(str, c);
	char *own = ft_strchr(str, c);
	if ((ori && own) || (!ori && !own))
		return;
	if (strlen(ori) == strlen(own) || !strcmp(ori, own))
		return;
	printf("ERROR in test %s %c:\noriginial: %s own: %s\n", str, c, ori, own);
}


int main(void)
{
	test("First string", 't');
	test("Second string", 's');
	test("Multiple u in string", 'u');
	test("Not found", 'z');
	test("LAST TEST in test", 'e');
	test("", '-');
	printf("Test ft_strchr completed!\n");
}