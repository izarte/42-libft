#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memchr(void *str, int c, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);

int main()
{
    char    str[20] = "que pasa puta";
	void	*ptr;

    write(1, str, 20);
	write(1, "\n", 1);

	ptr = ft_memchr(str, 'p', 6);
    write(1, ptr, 20);
	write(1, "\n", 1);

	ptr = ft_memset(str, '8', 3);
    write(1, ptr, 20);
	write(1, "\n", 1);
    write(1, str, 20);
	write(1, "\n", 1);
    
	ft_bzero(str, 3);
    write(1, str, 20);
	write(1, "\n", 1);

	ptr = ft_memcpy(str, "que pasa", 3);
    write(1, ptr, 20);
	write(1, "\n", 1);
    write(1, str, 20);
	write(1, "\n", 1);

	printf("1 = %d\n", ft_memcmp(str, "que", 3));
	printf("0 = %d\n", ft_memcmp(str, "qu ", 3));
	printf("1 = %d\n", ft_memcmp(str, "que ps", 5));
}
