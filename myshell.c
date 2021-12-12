#include<readline/readline.h> 
#include<readline/history.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 


void command(char *girdi,char *dizi[]){ 

if(strcmp(dizi[0],"tekrar")==0){ //eğer tekrar komutu girilmişse
  if (dizi[1] == NULL && dizi[2] == NULL) //ikinci ve üçüncü parametrelerinin null olup olmadığının komtorlü
    {
      printf("Eksik ya da hatalı komut girdiniz.\n"); //eğer null'sa hata mesajı yazar
    }
    else if (dizi[1] == NULL || dizi[2] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz..\n");
    } else{

  		printf("tekrar baslatiliyor\n");		
  		int e,f;
  		f = fork(); //tekrar fonks. için fork yapıyorım bu şekilde processin kopyası oluşturulur
            		if(f == 0){ 
                		e = execv("tekrar",dizi); //tekrar dosyamı çalıştırmak için de execv kullandım
                		perror("execv failed \n");
            }
            else{
                wait(&e); 
            }	
  		
  	}
  	}
  	
    
    if(strcmp(dizi[0],"islem")==0){ //eğer islem komutu girilirse de 
  	if (dizi[1] == NULL && dizi[2] == NULL && dizi[3] == NULL) //yine islem'den sonra ki kısmın null olup olmama kısmını kontrol ediyorum
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    }
    else if (dizi[1] == NULL || dizi[2] == NULL || dizi[3] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    } else{

  	int f,e;
  	printf("islem baslatiliyor\n");
  	
  	f = fork(); //fork yaparak aynı işlemi gerçekleştiriyorum
            if(f == 0){ 
                e = execv("islem",dizi);
                perror("execv failed \n");
                
            }
            else{
                wait(&e); 
            }
  	
  	}
  	
  	}
  	
  	
  	}
  	
  	int kontrol(char **commands){ //main fonks çağırılan dizim
     int result=0;
    int i;
    for (i = 0; i < 50; i++){ 
        if (strcmp(commands[i],"|")==0){ //dizimde | olup olmadığının kontrolü
            return result=0;
          
     }
      
  }
    printf("yok\n");
        return result=1;
}
  	
  	 void bol(char *girdi,char *dizi[], int count){ //eğer girilen dizi | iceriyorsa bolunur
             int bol=0;
		for(int i=0; i<count; i++){ 
			if(strcmp(dizi[i],"|")==0){ //dizimin | oldugu indeksi bulup
				bol=i;	//int degerime atıyorum			
			}
		}
		char * dizi1[bol]; // | bulundugu yere kadar ilk dizim oluyor
		for(int j=0; j<bol; j++){
		dizi1[j]=dizi[j];
		
		}
		dizi1[bol]=NULL;
		command(girdi,dizi1); //oluşturduğum ilk dizimi cagırıyorum
		
		char *dizi2[count-bol]; //ikinci komut icin | den sonrası icin ayarlıyorum
		int c=0;
		for(int j=bol+1; j<count; j++){ //iknici komut icin bir tane daha dizi olusturuyorum
			dizi2[c]=dizi[j];
			c++;
  }
  	
  	        dizi2[count-bol]=NULL; 
		command(girdi,dizi2);
		}
  	
  	
  	

int main(){
char **dizi=((char **) malloc (100*sizeof(char**)));


while (1) 
	{          
	  char* girdi;
	  int i=0;
	  int count=0;
	  
	
	 girdi = readline("\nmyshell>>"); //kullanıcıdan input değeri aldım ve myshell'de alıp devam etmek için readline kullandım
	  char* words = strtok(girdi, " "); //input boşluklara bölübür
	 
	  while(words!=NULL)	{ //null olana kadar girdimi words'e atadım
	   dizi[i]=words;
	   words=strtok(NULL," "); //boşluklara böldüm tekrardan
	   i++;
	   count++; //girilen komutun uzunluğunu bulabilmek için count yaptım
	 }
	 dizi[count]=NULL; //hata almamak için son elemanı NULL'a atadım	
	int j=0;
	if(count > 4){ //eğer count değeri 4'den fazla ise iki komut girilmiş demektir 		
	   if (kontrol(dizi)==0){ //yukarıda tanımlamış olduğum ispipe fonksiyonumda | olup olmama durummunu kontrol ediyorum	
             bol(girdi,dizi,count); //eğer | içeriyorsa bol fonksiyonumda komutlarımı bölüyorum    
   
   
    }else if (kontrol(dizi)==1){   // eğer | içermiyorsa program hata verir
            printf("hatali");
    }
    
	}else { //girilen komutlar 4'den küçükse 
	
	if(strcmp(girdi,"exit")==0){ //kullanıcıdan exit girilirse programdan çıkılır
	  printf("cikis yapiliyor..\n");
	return 0;
	
	}
	
	   else if(strcmp(girdi,"bash")==0){ //bash girilmesi durumunda bash çağırılır
	 printf("Bash baslıyor...\n");
         system("/bin/bash");	
		
	}
	 else if(strcmp(girdi,"clear")==0){	//sistemdeki clear çağırılır
         system("clear");
	
	}
	else if(strcmp(girdi,"ls")==0){	 //sistemdeki ls çağırılır
         system("/bin/ls");
	
	} else if ( (strcmp(girdi,"islem")!=0) && (strcmp(girdi,"tekrar")!=0 ) )    {  //buradaki komutlar dışında bir komut girilirse eksik veya hatalı yazısı gelir
	  printf("yanlis bir komut girdiniz, tekrar deneyiniz\n");
	
	}
	
	}
	      command(girdi,dizi); // yukarıda verdiğim if değerleri dışında bir komut girilirse command fonks. çağrılır.
	}
  return 0; 
}
