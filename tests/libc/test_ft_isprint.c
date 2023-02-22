#include <stdio.h>
#include <ctype.h>

#include "libft.h"

void	test(int c)
{
	int ori = isprint(c);
	int own = ft_isprint(c);
	if ((ori && !own) || (!ori && own))
		printf("ERROR in test %i:\noriginial: %i own: %i\n", c, ori, own);
}

int main(void)
{
	test('a');
	test('A');
	test('z');
	test('Z');
	test('s');
	test('S');
	test('0');
    test('9');
	test(' ');
	test('\0');
	test('p');
	test('.');
	test(-2);
	test(-100);
	test(31);
	test(32);
	test(127);
	test(128);

	printf("Test ft_isprint completed!\n");
}