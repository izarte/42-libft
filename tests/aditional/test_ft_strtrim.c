#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

int	ft_hasany(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

char	*strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	start;

	if (s1 == NULL || set == NULL)
		return ((char *) s1);
	s1_len = strlen(s1);
	start = 0;
	while (ft_hasany(set, s1[start]) && start < s1_len)
		start++;
	while (ft_hasany(set, s1[s1_len - 1]) && start < s1_len)
		s1_len--;
	return (ft_substr(s1, start, s1_len - start));
}

void	test(char const *str1, char const *str2)
{
	char *ori = strtrim(str1, str2);
	char *own = ft_strtrim(str1, str2);
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %s %s :\noriginial: %s own: %s\n", str1, str2, ori, own);
}

int main(void)
{
	test("No remove", "apstbss");
	test("No remove", "aps tbss");
	test("No remove.", "aps.tbss");
	test("remove static", "emovr");
	test("remove static", "remove");
	test("", "test");
	test("test", "");
	printf("Test ft_strtrim completed!\n");
}
