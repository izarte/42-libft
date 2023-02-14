#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../libft.h"

void	test(const char *str, char c)
{
	char *ori = strrchr(str, c);
	char *own = ft_strrchr(str, c);
	if ((ori && own) || (!ori && !own))
		return;
	if (strlen(ori) == strlen(own) && !strcmp(ori, own))
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
	printf("Test ft_strrchr completed!\n");
}

// void	test(const char *str, int d)
// {
// 	printf("Test: Data: \"%s\" Char: %i (%c)\n", str, d, d);
// 	printf(" - Original: \"%s\"\n", strrchr(str, d));
// 	printf(" - Custom  : \"%s\"\n", ft_strrchr(str, d));	
// }

// int		main(void)
// {
// 	test("Hola caracola", 'c');
// 	test("ESTOsi estono:D", ' ');
// 	test("hayvariasasenlafrase", 'a');
// 	test("no hay resultados en esta", '-');
// }