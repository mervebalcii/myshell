
#include<readline/readline.h> 
#include<readline/history.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <stdbool.h>

int IsPipe(char *commands[]){
   
    int i;
    for (i = 0; i < 50; i++){
        if (strcmp(commands[i],"|")==0){
          printf("a");
            return 0;
          
           
    }else{
    
    printf("b");
    return 1;
    }
    }
    return 0;
}

int main(){
char *dizi[100];
char *tekrar[2];

 

while (1) 
	{          
	  char* girdi;
	  int i=0;
	  int count=0;
	 strcpy(dizi,girdi);
	 girdi = readline("\nmyshell>>"); 
	  char* words = strtok(girdi, " ");
	  
	  while(words!=NULL)	
	{
	   dizi[i]=words;
	   words=strtok(NULL," "); 
	   count++;
	 
	}
	if(count > 4){
	    if(IsPipe(dizi)==0){
	     printf("| var");
	
	}
	else if(IsPipe(dizi)==1){
	  printf("hatali");
	}
	}else{
	printf("normal");
	
	} 
	} 
  return 0; 
}
