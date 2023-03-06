#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"

char	**split(char const *s, char c);

void test(const char *s, char c)
{
	int	i = 0;
	char **ori = split(s, c);
	char **own = ft_split(s, c);
	while (ori[i])
	{
		printf("%s\n", own[i]);
		if (strcmp(ori[i], own[i]))
			printf("ERROR in test %s %c :\noriginial: %s own: %s\n", s, c, ori[i], own[i]);
		i++;
	}
}

int main()
{
	// test("test", 'z');
	// test("testdasfasgrfdcafwasfdgrethgf with spaces to be splitted", ' ');
	// test("testdasfasgrfdcafwasfdgrethgf with spaces to be splitted afsadgaesdf waefasd fawsedfa wsedfasedfased fasdfgasdfas", ' ');
	// test("test with spaces", ' ');
	// test("a a a a a a a a a a a a a a a a a a", ' ');
	// test("test with spaces to be splitted", ' ');
	// test("test,with,commas,to,be,splitted", ',');
	// test("", ' ');
	test("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	// test("                         ", ' ');
	printf("Test ft_split completed!\n");
}


char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	**ft_free_array(char **arr);

static size_t	ft_countelements(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**init_split(char const *s, char c)
{
	char	**arr;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_countelements(s, c);
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	arr[len] = NULL;
	return (arr);
}

char	**split(char const *s, char c)
{
	char	**arr;
	size_t	index;
	size_t	i;
	size_t	start;

	arr = init_split(s, c);
	if (arr == NULL)
		return (NULL);
	index = 0;
	i = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[index++] = ft_substr(s, start, i - start);
		if (arr[index - 1] == NULL)
			return (ft_free_array(arr));
	}
	return (arr);
}
char	**ft_free_array(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
