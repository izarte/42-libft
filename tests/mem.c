#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memchr(void *str, int c, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);

const int SIZE = 13;

int main()
{
    char    str[17] = "que pasa puta";
	char	stro[17] = "que pasa puta";
	// char	str2[17] = "puta";
	void	*ptr;

    // write(1, str, SIZE);
	// write(1, "\n", 1);

	/* memchr */

	// ptr = ft_memchr(str, 'p', 6);
    // write(1, "memchr", 6);
	// write(1, ptr, SIZE);
	// write(1, "\n", 1);

	/* memset */

	// ptr = ft_memset(str, '8', 3);
    // write(1, "memset", 6);
	// write(1, ptr, SIZE);
	// write(1, "\n", 1);
    // write(1, str, SIZE);
	// write(1, "\n", 1);
    
	/* bzero */

	// ft_bzero(str, 3);
	// write(1, "bzero", 5);
    // write(1, str, SIZE);
	// write(1, "\n", 1);

	/* memcpy */

	ptr = ft_memcpy(str + 3, str + 4, 10);
	write(1, "ft_memcpy\n", 10);
    write(1, ptr, SIZE);
	write(1, "\n", 1);
    write(1, str, SIZE);
	write(1, "\n", 1);
	write(1, "memcpy\n", 7);
	ptr = memcpy(stro + 3, stro + 4, 10);
    write(1, ptr, SIZE);
	write(1, "\n", 1);
    write(1, stro, SIZE);
	write(1, "\n", 1);

	ft_memcpy(str, "que pasa puta", 17);
	ft_memcpy(stro, "que pasa puta", 17);
	/* memmove */
	
	write(1, "memmove\n", 8);
	write(1, stro, SIZE);
	write(1, "\n", 1);
	ptr = memmove(stro + 3, stro + 4, 10);
    write(1, ptr, SIZE);
	write(1, "\n", 1);
    write(1, stro, SIZE);
	write(1, "\n", 1);

//	printf("%d = %d\n", memcmp(str, "que", 3), ft_memcmp(str, "que", 3));
//	printf("%d = %d\n", memcmp(str, "qu", 3), ft_memcmp(str, "qu", 3));
//	printf("%d = %d\n", memcmp(str, "que ps", 5), ft_memcmp(str, "que ps", 5));
//	printf("%d = %d\n", memcmp(str, "que ps", 6), ft_memcmp(str, "que ps", 6));

	// ptr = memmove(str, str2, 4);
    // write(1, ptr, SIZE);
	// write(1, "\n", 1);
    // write(1, str, SIZE);
	// write(1, "\n", 1);
    // write(1, str2, SIZE);
	// write(1, "\n", 1);

	//printf("%s\n", (char *)memmove(str, "puta", 4));
}
