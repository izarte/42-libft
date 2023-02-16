#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../../libft.h"

void	test(void *str, size_t n)
{
	char buff[128];
	char buff2[128];
	char *ori = memcpy(buff, str,  n);
	char *own = (char *)ft_memcpy(buff2, str, n);
	if ((ori && own) || (!ori && !own))
		return;
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %p %li:\noriginial: %s own: %s\n", str, n, ori, own);
}

int main(void)
{
	test("Message copied", strlen("Message copied"));
	test("Message copied", 5);
	printf("Test ft_memcpy completed!\n");
}
