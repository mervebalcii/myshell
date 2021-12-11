#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int e;
    char *temp[3];
    temp[0] = argv[2];
    temp[1] = argv[3];
    temp[2] = NULL;
    
    e = execv(argv[1],temp);
 
    	
    return 0;
}
