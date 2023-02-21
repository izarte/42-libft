#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "../../libft.h"

void	putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
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

void	test(char *str)
{
	int fd1 = open("file_ori", O_WRONLY);
	int fd2 = open("file_own", O_WRONLY);
	putstr_fd(str, fd1);
	ft_putstr_fd(str, fd2);
	close(fd1);
	close(fd2);
	compareFiles("file_ori", "file_own");
}

int main()
{
	test("That is a test");
	test("This string should be in the file given.\nYes it is");
	test("berghbe<asrfgehargftueagña<erujfghnmxoñialewkrjsdnòpgfauheirnjf sdo`gvueajrsofdjgmk'2Q+E`ÇASDJOFMKETPODUFGHNKVWODSHBNJGV AOESRUHFGD '1q`2 'wlsañd,owariujsdkmfvàwsdcgkjnvwqIDSJAKGNXCVB9OAWPÑOIE KFomWSF SJDOIFGLVWÀESODJGMAPWE-ÑRSFJGCMVEALDFJNXGCV");
	printf("Test ft_putstr_fd completed!\n");
}