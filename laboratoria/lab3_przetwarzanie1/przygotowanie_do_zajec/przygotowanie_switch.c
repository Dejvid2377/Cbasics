#include <stdio.h>

int main()
{
    char menu[3] = " ";
    
    do {
        printf("Proste menu:\n");
        printf("  1 - Pozycja pierwsza\n");
        printf("  2 - Pozycja druga\n");
        printf("  3 - Pozycja trzecia\n");
        printf("  4 - Zakoñcz dzialanie\n");
        printf("Twoj wybor: ");
        
        scanf("%1s", menu);
        
        switch (menu[0]){
            case '1': printf("Wybrano pozycje pierwsza\n"); break;
            case '2': printf("Wybrano pozycje druga\n"); break;
            case '3': printf("Wybrano pozycje trzecia\n"); break;
            case '4': printf("Koniec dzialania programu\n"); break;
            default : printf("Nierozpoznane, sprobuj ponownie:\n "); 
        }
    }  while (menu[0] != '4');
    return 0;
}