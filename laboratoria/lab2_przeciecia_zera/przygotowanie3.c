#include <stdio.h>
#define MAX 5
#define MIN -5
#define STOP 99

void text (int i);

int main()
{
    int value = 1;
    int i=1;

    do  {
        text(i);
        scanf("%d",&value);

        if (value<-5 || value>5 && value!=STOP)    {printf("Bledna wartosc parametru!\n");}
        else if (value==STOP)         {printf("\n");}
        else                        {printf("Aktualna wartosc parametru: %d \n",value);}
        i++;

        } while (value!=STOP);
    return 0;
}

void text (int  i)
{
    printf("Podaj %d. wartosc parametru: ",i);
}