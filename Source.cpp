#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "SerialClass/SerialClass.h"

#define MAX_BUFFER 200 // tamaño max. cadenas de char que almacenan mens. de envio y recepcion
#define PAUSA_MS 200 //t espera [ms] envio mens.-recepcion respuesta 


int menu_ppal(void);
int Enviar_y_Recibir(Serial* Arduino, const char* mensaje_enviar, char* mensaje_recibir);

//mostrar menú principal

int menu_ppal(void) {

	int opcion;

	printf("\tMenu principal\n");
	printf("\n");
	printf("1-Registrar un nuevo jugador\n")
	printf("2-Iniciar partida\n");
	printf("3-Mostrar puntuacion global\n");
	printf("4-Salir\n");
	printf("\nSeleccione opcion:\n");

	scanf_s("%d", &opcion);

	return opcion;
}



int main(void) {

	Serial* Arduino;
	char puerto[] = "COM5"; //en el mio
	int opcion_menu;
	setlocale(LC_ALL, "es-ES");  //idioma castellano
	Arduino = new Serial((char*)puerto);

	do {
		opcion_menu = menu_ppal();
		switch (opcion_menu) {
		case 1:
			//funcion para registrar usuarios
			break;
		case 2:
			//funcion para jugar partida
			break;
		case 3:
			//funcion que imprima la puntuación global
			break;
		case 4:
			break;
		default:
			printf("\nOpcion incorrecta. Vuelva a introducir opcion.\n")
		}
	}while(opcion_menu != 4);

	return 0;
}



//conectar arduino y visual

int Enviar_y_Recibir(Serial* Arduino, const char* mensaje_enviar, char* mensaje_recibir){

	int bytes_recibidos = 0, total = 0;
	int intentos = 0, fin_linea = 0;
	Arduino->WriteData((char*)mensaje_enviar, strlen(mensaje_enviar));
	Sleep(PAUSA_MS);
	bytes_recibidos = Arduino->ReadData(mensaje_recibir, sizeof(char) * MAX_BUFFER - 1);

	while ((bytes_recibidos > 0 || intentos < 5) && fin_linea == 0)
	{
		if (bytes_recibidos > 0)
		{
			total += bytes_recibidos;
			if (mensaje_recibir[total - 1] == 13 || mensaje_recibir[total - 1] == 10)
				fin_linea = 1;
		}
		else
			intentos++;
		Sleep(PAUSA_MS);
		bytes_recibidos = Arduino->ReadData(mensaje_recibir + total, sizeof(char) * MAX_BUFFER - 1);
	}
	if (total > 0) {
		mensaje_recibir[total - 1] = '\0';
	}

	return total;
}