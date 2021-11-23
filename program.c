#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>


void holdon(int value){
sleep(value);

};

   int main(int argc, char *argv[])
   {
//программа включает и выключает светодиод с определенной задержкой
//задержку переключает дочерний процесс
//через каждые 5 переключений требуется ввести новое значение задержки    
   	   int i;
   	   int count = 0;
   	   int new_i;
   	   int flag = 0;
	   i = atoi(argv[1]);
	   char ch[15]= "";
           int     fd[2], nbytes;
           int value;
           pid_t   childpid;
           char    string[] = "Hello, world!\n";
           char    readbuffer[80];
           char * newval = string;
          
         
           pipe(fd);
           
           
           
           if((childpid = fork()) == -1)
           {
                   perror("fork");
                   exit(1);
           }
           while (ch != "0"){
          
           if(childpid == 0)
           {
            while (count < 5){
                   // Потомок 
                   char *file = "file.txt";
                  
		//printf("%s", values);
		   
		   
		   
                   holdon(i);
                   if (flag==0){
                  	FILE *f = fopen(file, "w");
                   	fprintf(f, "%s", "0\n");
                   	fflush(f);
                   	
                   	//printf("1\n");
                   	flag = 1;
                   	fclose(f);
                   }
                   else {
                   
                   	FILE *f = fopen(file, "w");
                   	fprintf(f, "%s", "1\n");
                   	fflush(f);
                   	
                   	//printf("0\n");
                   	flag = 0;
                   	fclose(f);
                   	
                   }
                  
                   
                   count=count+1;
                   }
                    close(fd[1]);
                   nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                   new_i = atoi(readbuffer);
                   i = atoi(readbuffer);
                   
                 count=0;
                 }
          
           else
           {
                   // Родитель 
                   printf("Input value!");
                   gets(ch); 
                   printf("got");
                   close(fd[0]);
                   write(fd[1], ch, strlen(ch));
                   
                   //exit(0);
                   
                   
                   
           }
           }
           printf("Closed!");
           return(0);
   }
