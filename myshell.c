
#include<readline/readline.h> 
#include<readline/history.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 


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
	printf("hatali komut sayisi");
	} else{
	
	
	
	
	
	}
	
	  
	} 
  return 0; 
}
