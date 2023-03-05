#include <stdio.h>
#include <ctype.h>
#include <string.h>


#include "libft.h"

char	*ft_strstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *) str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == *needle)
		{
			j = 0;
			while (needle[j] && str[i + j] && i + j < len)
			{
				if (str[i + j] != needle[j])
					break ;
				j++;
			}
			if (!needle[j])
				return ((char *) &str[i]);
		}
		i++;
	}
	return (NULL);
}


void	test(const char *str, const char *str2, size_t n)
{

	char *ori = ft_strstr(str, str2, n);
	char *own = ft_strnstr(str, str2, n);
	if ((ori && own) || (!ori && !own))
		return;
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %s %s:\noriginial: %s own: %s\n", str, str2, ori, own);
}


int main(void)
{
	test("First string", "string", 15);
	test("Second string", "Sec", 8);
	test("Multiple u in string", "u", 1);
	test("Multiple u in string", "u", 4);
	test("Multiple u in string", "u", 15);
	test("Not found", "exit", 10);
	test("LAST TEST in test", "TESTa", 5);
	printf("Test ft_strnstr completed!\n");
}
