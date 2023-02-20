#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "../../libft.h"


char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		return (ft_strdup(s2));
	}
	s1_len = strlen(s1);
	if (s2 == NULL)
		return (ft_strdup(s1));
	s2_len = strlen(s2);
	str = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

void	test(char const *str1, char const *str2)
{
	char *ori = strjoin(str1, str2);
	char *own = (char *)ft_strjoin(str1, str2);
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %s %s :\noriginial: %s own: %s\n", str1, str2, ori, own);
}

int main(void)
{
	test("string to be ", "completed");
	test("", "added");
	test("same", "");
	test("", "");
	printf("Test ft_strjoin completed!\n");
}
