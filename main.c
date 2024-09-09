#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "procesos_functions.h"

int main() {
	int newOrQuit;
	bool endPlanner = false, initialized = false;
	
	setlocale(LC_CTYPE, "Spanish");

	while (!endPlanner) {
		if (!initialized) {
			initProcessScheduler();
		} else {
			printf("\nMenú:\n1- Agregar nuevos procesos.\n2- Salir\n");
			while (scanf("%d", &newOrQuit) != 1 || newOrQuit < 0 || newOrQuit > 2) {
				printf("El valor ingresado no es válido, ingresa otro...\n");
				clearInputBuffer();
			};
			clearInputBuffer();
		
			if (newOrQuit == 1) {
				initProcessScheduler();
			} else {
				endPlanner = true;
			}	
		}
		
		initialized = true;	
	}
	printf("Gracias por usar el planificador de procesos. #ThisIsCS50 :)");
	getch();
	return 0;
}
