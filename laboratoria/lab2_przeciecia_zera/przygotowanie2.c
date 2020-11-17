#include <stdio.h>
#define PROG 20
int main()
{
    float temperatura;

    printf("Podaj temperature we Wroclawiu (k zeby zakonczyc): ");

    while(scanf("%f",&temperatura))
    {
        if (temperatura <= PROG)
        {
            printf("Nie jest zbyt cieplo!\n");
        }
        else
        {
            printf("Jest bardzo ladna pogoda!\n");
        }
    printf("Podaj temperature we Wroclawiu (k zeby zakonczyc): ");
    }
    
    printf("Koniec programu.\n");
    return 0;
}