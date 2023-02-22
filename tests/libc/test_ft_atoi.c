#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "libft.h"

void	test(const char *str)
{

	int ori = atoi(str);
	int own = ft_atoi(str);
	if (ori != own)
		printf("ERROR in test %s:\noriginial: %i own: %i\n", str, ori, own);
}


int main(void)
{
	test("12a3456789");
	test("123589");
	test("+18");
	test("-18");
	test("	 \n\t\v18");
	test("2147483647");
	test("-2147483646");
	test("a12a3456789");
	printf("Test ft_atoi completed!\n");
}
