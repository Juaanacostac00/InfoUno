#include <stdio.h>

int main(void)
{
    // Variables necesarias para el programa
    int cantAlumnos, nota, notaMin, notaMax, i = 0;
    float promedio, totalNotas;

    // Bloque para validadr la cantidad de alumnos 
    do {
        printf("Ingrese la cantidad de alumnos a evaluar: ");
        scanf("%d", &cantAlumnos);
        if (cantAlumnos <= 0) {
            printf("La cantidad de alumnos debe ser mayor a cero. Intente nuevamente.\n");
        }
    } while (cantAlumnos <= 0);
    
    // Bloque para ingresar las notas de los alumnos y calcular el promedio, nota mínima y nota máxima
    while (i < cantAlumnos) {

        // Bloque para validar que la nota ingresada esté entre 0 y 100
        do{
            printf("Ingrese la nota del alumno %d (0-100): ", i + 1);
            scanf("%d", &nota);
            if (nota < 0 || nota > 100) {
                printf("La nota debe estar entre 0 y 100. Intente nuevamente.\n");
            }
        } while (nota < 0 || nota > 100);

        totalNotas += nota;

        // Condicional para establecer la nota mínima y máxima
        if (i == 0) {
            notaMin = nota;
            notaMax = nota;
        } else {
            if (nota < notaMin) {
                notaMin = nota;
            }
            if (nota > notaMax) {
                notaMax = nota;
            }
        }

        i++;
    }
    promedio = totalNotas / cantAlumnos;

    printf("El promedio de las notas es: %.2f\n", promedio);
    printf("La nota mínima es: %d\n", notaMin); 
    printf("La nota máxima es: %d\n", notaMax);

    return 0;
}