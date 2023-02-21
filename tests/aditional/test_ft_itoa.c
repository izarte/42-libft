#include <stdio.h>
#include <string.h>

#include "../../libft.h"

void test(int n, char *str)
{
	char *own = ft_itoa(n);
	if (strcmp(own, str))
		printf("ERROR in test %i :\noriginial: %s own: %s\n", n, str, own);
}

int main()
{
	test(30, "30");
	test(8, "8");
	test(-8, "-8");
	test(-123456789, "-123456789");
	test(123456789, "123456789");
	test(-2147483648, "-2147483648");
	test(-2147483647, "-2147483647");
	test(2147483647, "2147483647");
	printf("Test ft_itoa completed!\n");
}