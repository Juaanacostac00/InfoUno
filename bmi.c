#include <stdio.h>

int main()
{
    float peso, altura;
    printf("Ingrese su peso en KG: ");
    scanf("%f", &peso);
    
    printf("Ingrese su altura en metros: ");
    scanf("%f", &altura);

    printf("\nSu índice de masa corporal es de: %.2f\n", peso / (altura * altura));
    printf("\nA continuación se detallará una tabla con el índice y condición:\n");
    printf("      Índice      |      Condición   \n");
    printf("------------------|------------------\n");
    printf("     < 18.5kg     |      Bajo peso \n");
    printf(" 18.5kg a 24.9kg  |       Normal \n");
    printf(" 25.0kg a 29.9kg  |      Sobrepeso \n");
    printf("     >= 30kg      |      Obesidad \n");
    
    return 0;
}
