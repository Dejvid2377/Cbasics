#include <stdio.h>

int main()
{
    for (int i=1; i<99;i++){
            while (i%10)
            {
                printf("%3d",i);
                i++;
            }
            if (i!=100)
            {
                printf("%3d\n",i);
            }
            else {  printf("\n");   }
    }
    return 0;
}