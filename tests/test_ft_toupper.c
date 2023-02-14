#include <stdio.h>
#include <ctype.h>

#include "../libft.h"

void	test(int c)
{
	int ori = toupper(c);
	int own = ft_toupper(c);
	if (ori != own)
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
	printf("Test ft_isdigit completed!\n");
}