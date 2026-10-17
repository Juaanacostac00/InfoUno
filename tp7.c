// https://github.com/Juaanacostac00/InfoUno

#include <stdio.h>
#define TAM 3

int codigos[TAM];
float precios[TAM];

int controlCodigo(int i){
    int codUsuario;
    
    do {
        printf("Código de barra del producto N° %d (Entre 1 y 999999999): ", i+1);
        scanf("%d", &codUsuario);
        if(codUsuario > 999999999 || codUsuario < 1){
            printf("Error. El código debe estar entre 1 y 999999999, intente nuevamente.\n");
        }
    } while(codUsuario > 999999999 || codUsuario < 1);
    
    return codUsuario;
}

float controlPrecio(int i){
    float preUsuario;
    
    do {
        printf("Precio del producto N° %d (%d): ", i+1, codigos[i]);
        scanf("%f", &preUsuario);
        if(preUsuario < 0){
            printf("Error. El precio no puede ser negativo\n");
        }
    } while(preUsuario < 0);
        
    return preUsuario;
}

void muestraMayor(){
    float mayor = precios[0];
    int codigoMayor = codigos[0];

    for(int i = 1; i < TAM; i++){
        if(precios[i] > mayor){
            mayor = precios[i];
            codigoMayor = codigos[i];
        }
    }
    
    printf("\nProducto más caro: (%d) %.2f", codigoMayor, mayor);
}

void muestraMenor(){
    int codigoMenor = codigos[0];
    float menor = precios[0];
    
    for(int i = 1; i < TAM; i++){
        if(precios[i] < menor){
            menor = precios[i];
            codigoMenor = codigos[i];
        }
    }
    
    printf("\nProducto más barato: (%d) %.2f", codigoMenor, menor);
}

int main()
{
    printf("Ingrese el código y precio de %d productos:\n", TAM);
    
    for(int i = 0; i < TAM; i++){
        codigos[i] = controlCodigo(i);
        precios[i] = controlPrecio(i);
    }
    
    printf("Listado completo de los productos:\nCódigo    | Precio\n");
    for(int i = 0; i < TAM; i++){
        printf("%d    | %.2f\n", codigos[i], precios[i]);
    }
    
    muestraMayor();
    muestraMenor();
    
    return 0;
}

