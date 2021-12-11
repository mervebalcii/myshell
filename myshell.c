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
  if (inp[1] == NULL && inp[2] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    }
    else if (inp[1] == NULL || inp[2] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    } else{

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
  	}
  	
    
    if(strcmp(inp[0],"islem")==0){
  	if (inp[1] == NULL && inp[2] == NULL && inp[3] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    }
    else if (inp[1] == NULL || inp[2] == NULL || inp[3] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    } else{

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

char *piped_commands[90];

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
	
	//     execArgsPiped(dizi, piped_commands);
            printf("buldu\n");
           
      
           
    }else if (IsPipe(dizi)==1){
    
            printf("hatali");
    }
    
	}else {
	
	if(strcmp(girdi,"exit")==0){
	  printf("cikis yapiliyor..\n");
	return 0;
	
	}
	
	   else if(strcmp(girdi,"bash")==0){
	 printf("Bash baslıyor...\n");
         system("/bin/bash");
	
	
	
	}
	 else if(strcmp(girdi,"clear")==0){	
         system("clear");
	
	}
	else if(strcmp(girdi,"ls")==0){	
         system("/bin/ls");
	
	} else if ( (strcmp(girdi,"islem")!=0) && (strcmp(girdi,"tekrar")!=0 ) )    {  
	  printf("yanlis bir komut girdiniz, tekrar deneyiniz\n");
	
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
