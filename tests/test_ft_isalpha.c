#include <stdio.h>
#include <ctype.h>

#include "../libft.h"

void	test(int c)
{
	int ori = isalpha(c);
	int own = ft_isalpha(c);
	if ((ori && !own) || (!ori && own))
		printf("ERROR:\noriginial: %i own: %i\n", ori, own);
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
	test(' ');
	test('\0');
	test('p');
	test('.');
	test(-2);
	test(-100);
	printf("Test ft_isalpha completed!\n");
}