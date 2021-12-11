
#include<readline/readline.h> 
#include<readline/history.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <stdbool.h>
void command(char *input,char *inp[]){
if(strcmp(inp[0],"tekrar")==0){
  		printf("tekrar baslıyor...\n");
  		
  		int e,f;
  		f = fork(); 
            		if(f == 0){ 
                		e = execv("tekrar",inp);
                		perror("execv failed \n");
            }
            else{
                wait(&e); 
            }	
  		
  	}
  	if(strcmp(inp[0],"islem")==0){
  	int f,e;
  	printf("islem baslıyor...\n");
  	
  	f = fork(); 
            if(f == 0){ 
                e = execv("islem",inp);
                perror("execv failed \n");
                
            }
            else{
                wait(&e); 
            }
  	
  	
  	
  	}
  	
  	
  	}
int IsPipe(char **commands){
int result=0;
    int i;
    for (i = 0; i < 50; i++){
        
        if (strcmp(commands[i],"|")==0){
            printf("buldu\n");
            return result=0;
          
     }
        
      
  }
    printf("yok\n");
        return result=1;
}



int main(){
char* ilk_girdi;
char **dizi=((char **) malloc (100*sizeof(char**)));
char *tekrar[2];

 

while (1) 
	{          
	  char* girdi;
	  int i=0;
	  int count=0;
	  int size=0;
	
	 girdi = readline("\nmyshell>>"); 
	
	//  strcpy(dizi,girdi);
	  char* words = strtok(girdi, " ");
	 
	  while(words!=NULL)	
	
	{
	   dizi[i]=words;
	   words=strtok(NULL," "); 
	   i++;
	   count++;
	 
	  
	  
	 }
	 dizi[count]=NULL;
	
	int j=0;
		
	
	if(count > 4){
	
	
		
	   if (IsPipe(dizi)==0){
            printf("buldu\n");
           
      
           
    }else if (IsPipe(dizi)==1){
    
            printf("hatali");
    }
    
	}else {
	
	if(strcmp(girdi,"exit")==0){
	  printf("cikis yapiliyor..\n");
	return 0;
	
	}
	
	   if(strcmp(girdi,"bash")==0){
	 printf("Bash baslıyor...\n");
         system("/bin/bash");
	
	
	
	}
	 if(strcmp(girdi,"clear")==0){	
         system("clear");
	
	}
	if(strcmp(girdi,"ls")==0){	
         system("/bin/ls");
	
	}
	
	}
	char * dizii[5];
		for(int i=0; i<5; i++){
			dizii[i]=dizi[i];
		}
		dizi[5]=NULL;
		command(girdi,dizi);
	}
  return 0; 
}
