#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "../../libft.h"

char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	siz;

	if (s == NULL)
		return (NULL);
	siz = strlen(s);
	if (start > siz)
	{
		str = malloc(sizeof(char));
		if (str != NULL)
			str[0] = '\0';
		return (str);
	}
	if (len > siz - start)
		len = siz - start;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}


void	test(char const *str, unsigned int start, size_t len)
{
	char *ori = substr(str, start, len);
	char *own = (char *)ft_substr(str, start, len);
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %s %i %li:\noriginial: %s own: %s\n", str, start, len, ori, own);
}

int main(void)
{
	test("This is total string, this is a substring, this is extra", 22, 19);
	test("This is total string, this is a substring, this is extra", 0, 22);
	test("This is total string, this is a substring, this is extra", 43, 13);
	test("This is total string, this is a substring, this is extra", 51, 13);
	test("This is total string, this is a substring, this is extra", 51, 18);
	printf("Test ft_substr completed!\n");
}
