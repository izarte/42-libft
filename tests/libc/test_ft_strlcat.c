#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <bsd/string.h>

#include "libft.h"

size_t ori_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
    int d_len,s_len,offset,src_index;

    /* obtain initial sizes */
    d_len = strlen(dst);
    s_len = strlen(src);

    /* get the end of dst */
    offset = d_len;

    /* append src */
    src_index = 0;
    while( *(src+src_index) != '\0' )
    {
        *(dst+offset) = *(src+src_index);
        offset++;
        src_index++;
        /* don't copy more than dstsize characters
           minus one */
        if(offset==(int)dstsize-1)
            break;
    }
    /* always cap the string! */
    *(dst+offset) = '\0';

    return( d_len+s_len );
}


void	test(const char *str, int n)
{
	char buff[128] = "DO NOT TOUCH \0";
	char buff2[128] = "DO NOT TOUCH \0";
	int ori = ori_strlcat(buff, str, n);
	int own = ft_strlcat(buff2, str, n);
	if (ori != own || strcmp(buff, buff2))
		printf("ERROR in test %s:\noriginial: %s %i own: %s %i\n", str, buff, ori, buff2, own);
}


int main(void)
{
	test("here\0", 14 + 4);
	test("here\0", 14 + 3);
	test("here\0", 14 + 1);
	test("\0", 14 + 1);
	printf("Test ft_strlcat completed!\n");
}
