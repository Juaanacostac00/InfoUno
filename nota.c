#include <stdio.h>

int main()
{
    int nota;
    printf("Ingrese su clasificación (0-100): ");
    scanf("%d", &nota);
    
    if(nota >= 90)
    {
        printf("Clasificación: A\n");
    }
    else if(nota >= 80 && nota < 90)
    {
        printf("Clasificación: B\n");
    }
    else if(nota >= 70 && nota < 80)
    {
        printf("Clasificación: C\n");
    }
    else if(nota >= 60 && nota < 70)
    {
        printf("Clasificación: D\n");
    }
    else
    {
        printf("Clasificación: F\n");
    }
    
    return 0;
}