#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int number1 = atoi(argv[0]);
    int number2 = atoi(argv[1]);
    int sum = number1-number2;
    printf("%d - %d = %d \n",number1,number2,sum);
    return 0;
}
