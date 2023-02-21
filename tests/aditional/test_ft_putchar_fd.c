#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>

#include "../../libft.h"

void	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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

void	test(char c)
{
	int fd1 = open("file_ori", O_WRONLY);
	int fd2 = open("file_own", O_WRONLY);
	putchar_fd(c, fd1);
	ft_putchar_fd(c, fd2);
	close(fd1);
	close(fd2);
	compareFiles("file_ori", "file_own");
}

int main()
{
	test('I');
	test('Z');
	test('R');
	test('i');
	test('z');
	test('r');
	printf("Test ft_putchar_fd completed!\n");
}