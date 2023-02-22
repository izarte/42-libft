#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"

void	test(const char *str_ori, const char *str_own, char *buff_ori, char *buff_own, size_t n)
{
	char *ori = memmove(buff_ori, str_ori,  n);
	char *own = (char *)ft_memmove(buff_own, str_own, n);
	if ((ori && own) || (!ori && !own))
		return;
	if (!strcmp(ori, own))
		return;
	printf("ERROR in test %s %s %li:\noriginial: %s own: %s\n", str_ori, buff_ori, n, ori, own);
}

int main(void)
{
    char buff_ori[128] = "This text should be overwritten";;
    char buff_own[128] = "This text should be overwritten";;
    test(&buff_ori[20], &buff_own[20], buff_ori, buff_own, 11);
    test(&buff_ori[5], &buff_own[5], buff_ori, buff_own, 11);
    test("", "", buff_ori, buff_own, 1);
	
	printf("Test ft_memmove completed!\n");
}
