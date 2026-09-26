#include <stdio.h>
#include <math.h>

float calcularAreaRectangulo(float longitud, float altura){
    float area;
    return area = longitud * altura;
}

float calcularPerimetroRectangulo(float longitud, float altura){
    float perimetro;
    return perimetro = 2 * (longitud + altura);
}

float calcularAreaCirculo(float radio){
    float area;
    return area = M_PI * (radio * radio);
}

float calcularPerimetroCirculo(float radio){
    float perimetro;
    return perimetro = 2 * M_PI * radio;
}

void imprimirResultados(float area, float perimetro, int figura){
    if(figura == 1){
        printf("El área del rectángulo es: %.2fcm\n", area);
        printf("El perímetro del rectángulo es: %.2fcm\n", perimetro);
    }
    
    else{
        printf("El área del círculo es: %.2fcm\n", area);
        printf("El perímetro del círculo es: %.2fcm\n", perimetro);
    }
}

int main()
{
    int opcion;
    float radio, longitud, altura;
    
	do{
	    printf("Ingrese la figura que desea calcular (1: rectángulo, 2: círculo): ");
	    scanf("%d", &opcion);
	    
	    switch(opcion){
	       case 1:
	           printf("Ingrese la longitud del rectángulo (En cm): ");
	           scanf("%f", &longitud);
	           printf("Ingrese la altura del rectángulo (En cm): ");
	           scanf("%f", &altura);
	            
	           imprimirResultados(calcularAreaRectangulo(longitud, altura), calcularPerimetroRectangulo(longitud, altura), opcion);
	           break;
	       case 2:
	           printf("Ingrese el radio del círculo (En cm): ");
	           scanf("%f", &radio);
	           
	           imprimirResultados(calcularAreaCirculo(radio), calcularPerimetroCirculo(radio), opcion);
	           break;
	       default:
	           printf("Ingrese un valor valido.\n");
	           break;
	    }
	    
	} while(opcion > 2 || opcion < 1);

	return 0;
}