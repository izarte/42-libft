#include <stdio.h>
#include <string.h>

#include "../../libft.h"

void	test(char* c)
{
	int ori = strlen(c);
	int own = ft_strlen(c);
	if (ori != own)
		printf("ERROR in test %s:\noriginial: %i own: %i\n", c, ori, own);
}

int main(void)
{
	test("array normal");
	test("");
	test("también con ñ");
	test("\0");
	test("a");

	printf("Test ft_strlen completed!\n");
}