// https://github.com/Juaanacostac00/InfoUno

#include <stdio.h>
#include <stdlib.h>

#define TAM_NOMBRE_ESTUDIANTE 80
#define TAM_NOMBRE_MATERIA 80

typedef struct {
  char nombre[TAM_NOMBRE_MATERIA];
  int cantidad_parciales;
  int *parcial;
  float promedio;
} materia_t;

struct estudiante {
  int legajo;
  char nombre[TAM_NOMBRE_ESTUDIANTE];
  int cantidad_materias;
  materia_t *materia;
};

struct estudiante cargar_estudiante(void);
void imprimir_estudiante(struct estudiante);
materia_t* reservar_materias(int);
void liberar_materias(materia_t*);
int* reservar_parciales(int);
void liberar_parciales(int*);
void cargar_materia(materia_t*);
void cargar_parciales(materia_t*);
void calcular_promedio(materia_t*);

int main(void){
  struct estudiante est1;

  est1 = cargar_estudiante();
  imprimir_estudiante(est1);
  
  for(int i = 0; i < est1.cantidad_materias; i++) {
	  liberar_parciales(est1.materia[i].parcial);
  }
  
  liberar_materias(est1.materia);

  return 0;
}

struct estudiante cargar_estudiante(void) {
  struct estudiante e;

  printf("Ingrese legajo del estudiante: ");
  scanf("%d", &e.legajo);

  printf("Ingrese nombre del estudiante: ");
  scanf(" %80[^\n]s", e.nombre);

  printf("Ingrese la cantidad de materias a cargar: ");
  scanf("%d", &e.cantidad_materias); 
  
  e.materia = reservar_materias(e.cantidad_materias);

  for(int i = 0; i < e.cantidad_materias; i++) {
    cargar_materia(&e.materia[i]);
  }
  return e;
}

void imprimir_estudiante(struct estudiante e) {
  printf("%10d", e.legajo);
  printf(" %s\n", e.nombre);

  for (int m = 0; m < e.cantidad_materias; m++) {
	printf("%s:", e.materia[m].nombre);
	  
	for (int i = 0; i < e.materia[m].cantidad_parciales; i++) {
	  printf("%5d", e.materia[m].parcial[i]);
	}
	  printf("  Promedio: %.2f\n", e.materia[m].promedio);
  }

  printf("\n");
}

void cargar_materia(materia_t *p) {
  printf("Ingrese el nombre de la materia: ");
  scanf(" %80[^\n]s", p->nombre);
  printf("¿Cuántos parciales tiene %s? ", p->nombre);
  scanf("%d", &p->cantidad_parciales);

  p->parcial = reservar_parciales(p->cantidad_parciales);

  cargar_parciales(p);
}

void cargar_parciales(materia_t *p) {
  for (int i = 0; i < p->cantidad_parciales; i++) {
	  int nota = 0;
	  do {
		  printf("Ingrese calificación del %d parcial (1-10): ", i + 1);
		  scanf("%d", &nota);
		  
		  if (nota < 1 || nota > 10) {
			  printf("ERROR: La nota debe estar entre 1 y 10. Intente nuevamente.\n");
		  }
	  } while (nota < 1 || nota > 10);
	  
	  *(p->parcial + i) = nota;
  }
  calcular_promedio(p);
}

materia_t* reservar_materias(int n) {
  materia_t *p = NULL;

  p = malloc(n * sizeof(materia_t));
  if (p == NULL) {
    printf("No se pudo reservar memoria. Fin del programa.\n");
    exit(1);
  }

  return p;
}

int* reservar_parciales(int n) {
  int *p = NULL;

  p = malloc(n * sizeof(materia_t));
  if (p == NULL) {
    printf("No se pudo reservar memoria. Fin del programa.\n");
    exit(1);
  }

  return p;
}

void liberar_parciales(int *p) {
  if (p != NULL)
    free(p);
}

void liberar_materias(materia_t *p) {
  if (p != NULL)
    free(p);
}

void calcular_promedio(materia_t *p){
	float sumaNotas = 0;
	
	for(int i = 0; i < p->cantidad_parciales; i++){
		sumaNotas += *(p->parcial + i);
	}
	
	p->promedio = sumaNotas / p->cantidad_parciales;
}
