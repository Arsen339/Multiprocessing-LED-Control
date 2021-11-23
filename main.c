#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
int main(int argс, char *argv[]) 
{
//программа включает и выключает светодиод с определенной задержкой
// вызов:   ./main arg | ./led -s
//задержку переключает дочерний процесс
	char str[100];
	strcpy(str, "./script.sh ");
	//strcpy(str, "./outf ");
	strcat(str, argv[1]); 
	printf("%s", str);
	
	
	FILE* stream = popen(str, "w");
	fprintf(stream, "000");
	pclose(stream);





return 0;
}
