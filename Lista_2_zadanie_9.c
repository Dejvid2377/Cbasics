#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, n;

    int mnozenie(int a, int b); 
    int dodawanie(int a, int b);
    
    printf("Podaj liczbe ktora ma zostac podstawa przy potegowaniu: ");
    scanf("%d",&x);
    
    printf("Podaj liczbe ktora ma zostac wykladnikiem potegowania: ");
    scanf("%d",&n);
    
    printf("%d do potegi %d dla funkcji MNOZENIE wynosi: %d.\n", x, n, mnozenie(x,n));
    printf("a w przypadku funkcji DODAWANIE: %d.\n", dodawanie(x,n));
    

    return 0;
}

int mnozenie (int a, int b)
{
    int podstawa = 1;

    if (b==0)
    {
        a=1;
    }
    else if (b==1) 
    {
        a=a;
    }
    else
    {
        for (int i=0;i<b;i++)
        {
            podstawa*=a;
        }
        a = podstawa;
    }

    return a;
}

int dodawanie (int a, int b)
{
    int podstawa = 0;
    int cykl = a;

    if (b==0)
    {
        a = 1;
    }
    else if (b==1);
    else
    {
        for (int i=1; i<b; i++)
        {
            for (int j=0; j<cykl; j++)
            {
                podstawa+=a;
            }
            a = podstawa;
            podstawa = 0;
        }
    }
    return a;
}


    
    
    