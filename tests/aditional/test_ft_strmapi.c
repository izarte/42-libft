#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

char	*strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = malloc(strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f((unsigned int) i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	f1(unsigned int i, char c)
{
	i++;
	return (c);
}

char	f2(unsigned int i, char c)
{
	return (c + i);
}

void	test(const char *str, char (*f)(unsigned int, char))
{
	char *ori = strmapi(str, f);
	char *own = ft_strmapi(str, f);
	if (strcmp(ori, own))
		printf("ERROR in test %s:\noriginial: %s own: %s\n", str, ori, own);
	
}

int	main()
{
	test("test array", f1);
	test("", f1);
	test("test array", f2);
	test("", f2);
	printf("Test ft_strmapi completed!\n");
}