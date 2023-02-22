#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	if (s == NULL)
		return ;
	len = strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

void	f1(unsigned int i, char *c)
{
	i++;
	*c = *c;
}

void	f2(unsigned int i, char *c)
{
	*c = *c + i;
}

void	test(char *str1, char *str2, void (*f)(unsigned int, char*))
{
	striteri(str1, f);
	ft_striteri(str2, f);
	if (strcmp(str1, str2))
		printf("ERROR in test %s:\noriginial: %s own: %s\n", str1, str1, str2);
	
}

int	main()
{
	char	str1[] = "test array";
	char	str1_1[] = "";
	char	str2[] = "test array";
	char	str2_1[] = "";

	test(str1, str2, f1);
	test(str1_1, str2_1, f1);
	test(str1, str2, f2);
	test(str1_1, str2_1, f2);
	printf("Test ft_striteri completed!\n");
}