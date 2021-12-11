#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *inp[])
{
    int num = atoi(inp[2]);
    for(int i=0; i<num; i++){
        printf("%s \n",inp[1]);
    }
    return 0;
    }
