#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

#include "libft.h"

void	putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void compareFiles(char *name1, char *name2){
   FILE *file1 = fopen(name1, "r");
   FILE *file2 = fopen(name2, "r");
   if (file1 == NULL || file2 == NULL){
      printf("Error : Files not open");
      exit(0);
   }
   char ch1 = getc(file1);
   char ch2 = getc(file2);
   int error = 0, pos = 0, line = 1;
   while (ch1 != EOF && ch2 != EOF){
      pos++;
      if (ch1 == '\n' && ch2 == '\n'){
         line++;
         pos = 0;
      }
      if (ch1 != ch2){
         error++;
         printf("Error in line: %d \tError Position : %d ", line, pos);
      }
      ch1 = getc(file1);
      ch2 = getc(file2);
   }
}

void	test(int n)
{
	int fd1 = open("file_ori", O_WRONLY);
	int fd2 = open("file_own", O_WRONLY);
   if (!fd1 || !fd2)
   {
      printf("Files can't be opened");
      return ;
   }
	putnbr_fd(n, fd1);
	ft_putnbr_fd(n, fd2);
	close(fd1);
	close(fd2);
	compareFiles("file_ori", "file_own");
}

int main()
{
	test(30);
	test(8);
	test(-8);
	test(-123456789);
	test(123456789);
	test(-2147483648);
	test(-2147483647);
	test(2147483647);
	printf("Test ft_putnbr_fd completed!\n");
}