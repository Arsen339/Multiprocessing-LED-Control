#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

void holdon(int value){
/*Функция, останавливающая программу на value секунд*/
sleep(value);

};

int main(int argc, char *argv[])
{
// включение и выключение светодиода с определенной задержкой	
int i;
i = atoi(argv[1]);
printf("%d", i);
fflush(NULL);
while (1>0){
	holdon(i);
	printf("0");
	fflush(NULL);
	holdon(i);
	printf("1");
	fflush(NULL);

}	
	
	
	
return 0;
	
}
