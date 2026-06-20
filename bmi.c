#include <stdio.h>

int main()
{
    float peso, altura, imc;
   
    do{
        printf("Ingrese su peso en KG: ");
        scanf("%f", &peso);

        if(peso <= 0)
        {
            printf("El peso debe ser un número positivo. Por favor, intente de nuevo.\n");
        }
    } while(peso <= 0);
    
    do{
        printf("Ingrese su altura en metros: ");
        scanf("%f", &altura);

        if(altura <= 0)
        {
            printf("La altura debe ser un número positivo. Por favor, intente de nuevo.\n");
        }
    } while(altura <= 0);
    
    imc = peso / (altura * altura);

    printf("\nA continuación se detallará una tabla con el índice y condición:\n");
    printf("      Índice      |      Condición   \n");
    printf("------------------|------------------\n");
    printf("     < 18.5kg     |      Bajo peso \n");
    printf(" 18.5kg a 24.9kg  |       Normal \n");
    printf(" 25.0kg a 29.9kg  |      Sobrepeso \n");
    printf("     >= 30kg      |      Obesidad \n");
   
    printf("\nSu índice de masa corporal es de: %.2f\n", imc);
    if(imc < 18.5)
    {
        printf("\nSu condición es: Bajo peso\n");
    }
    else if(imc >= 18.5 && imc <= 24.9)
    {
        printf("\nSu condición es: Normal\n");
    }
    else if(imc >= 25.0 && imc <= 29.9)
    {
        printf("\nSu condición es: Sobrepeso\n");
    }
    else
    {
        printf("\nSu condición es: Obesidad\n");
    }

    return 0;
}

// Link del repositorio: https://github.com/Juaanacostac00/InfoUno/tree/main