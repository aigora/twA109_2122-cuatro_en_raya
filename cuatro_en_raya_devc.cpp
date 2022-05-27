#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define ANCHO 6         // Ancho del tablero
#define LARGO  6       // Largo del tablero
#define FMAX 35       // Numero de fichas maximo
#define FICHAS_FIN 4 // Numero de fichas para terminar

const char* jugadores[2][2] =
{
    {"Primer", "ROJO"},
    {"Segundo", "AMARILLO"}
};

typedef struct
{
	char nombre_registrado[100];
	char jugador[50];
}nombre;

typedef struct
{
    int pos[2]; // X y Y
    int num_jugador; // 1 o 2
} Fichas;

void inicio(char tablero[LARGO][ANCHO]);
void imprime_tablero(char tablero[LARGO][ANCHO], int turno,char nombre1[],char nombre2[]);
void mete_ficha(char tablero[LARGO][ANCHO], int* pos, int turno, Fichas* fichas, int num_fichas);
void inserta_ficha(Fichas* fichas, int num_fichas, int X, int Y, int num_jugador);
bool juego_terminado(char tablero[LARGO][ANCHO], int turno);


int main(int argc, char* argv[]) 
{

		//Aqui Empieza el codigo del Menú

	int opcion1,opcion2,ctrl, cantidad_usuarios=0,i=0,jugadores_iniciados=0,no_coincide=0;
	char nombre_inicio[100],nombre_registrar[50];
	nombre  nombres_registrados[100],jugadores[1];
	
	int turno = 0, posicion = 0;
    bool end = false, next = false;

    char tablero[LARGO][ANCHO];

    Fichas fichas[FMAX];
    int num_fichas = 0;
	
	FILE *registrados,*historial;
	
	//Leer y contar jugadores registrados
	
	registrados=fopen("Registrados.txt","r");
		do
		{
			ctrl=fscanf(registrados,"%s",nombres_registrados[i].nombre_registrado);
			
			i++;
			cantidad_usuarios++;
		}while(ctrl==1);
		
		cantidad_usuarios--;
		printf("Hay %d jugadores registrados.\n",cantidad_usuarios);
	
	do
	{
		printf("Que quieres hacer?\n");
		printf("1) Jugar.\n");
		printf("2) Ver usuarios registrados.\n");
		printf("3) Salir\n");
		scanf("%d",&opcion1);
	
	
		switch(opcion1) //Opcion jugar o ver historial
		{
			case 1:
				printf("1) Iniciar Sesion.\n");
				printf("2) No estas registrado? Crea un usuario nuevo.\n");
				scanf("%d",&opcion2);
				
			
				switch(opcion2) //Dentro de opcion jugar. Opcion iniciar sesion o registrarse.
				{
					case 1:
						printf("Dame tu nombre de usuario: \n");
						scanf("%s",nombre_inicio);
						
						
						registrados=fopen("Registrados.txt","r");
						i=0;
						no_coincide=0;
						for(i=0;i<=cantidad_usuarios;i++)  //Recorre la lista de usuarios registrados
						{
						
							ctrl=fscanf(registrados,"%s",nombres_registrados[i].nombre_registrado);
							if(ctrl==1)
							{
								if(strcmp(nombres_registrados[i].nombre_registrado,nombre_inicio)==0)  //Si el nombre ingresado esta ya registrado
								{
									printf("Iniciando sesion...\n");
									strcpy(jugadores[jugadores_iniciados].jugador,nombres_registrados[i].nombre_registrado);
									jugadores_iniciados++;
									break;
								}
								else
								{
									no_coincide++;
								}
								
							}
						if(no_coincide==cantidad_usuarios)  //Si recorre la lista entera y no hay coincidencias con ningun nombre
						printf("Nombre no registrado.\n");
						system("PAUSE");
						}
						if(cantidad_usuarios==0)
						{
						
						printf("Error.Todavia no hay usuarios registrados\n");
						system("PAUSE");
						}
						
						break;
					
					case 2:
						printf("Dame tu nombre de usuario:\n");
						scanf("%s",nombre_registrar);
						
						registrados=fopen("Registrados.txt","a");
						
						if(registrados==NULL)
						{
							printf("\nError.");							
						}
						else
						{
							printf("Registrando a %s...\n",nombre_registrar);
							system("PAUSE");
							fprintf(registrados,"\n%s\n",nombre_registrar);
							cantidad_usuarios++;
							fclose(registrados);
						}
						break;
				}
			break;
			
			case 2:
				printf("Usuarios registrados:\n");     //Te enseña los jugadores que estan registrados y los nombres con los que puedes
				                                 
				
				registrados=fopen("Registrados.txt","r");
			do
			{
				ctrl=fscanf(registrados,"%s",nombres_registrados[i].nombre_registrado);
				
				printf("%s\n",nombres_registrados[i].nombre_registrado);
				i++;
			}while(ctrl==1);
				
				fclose(registrados);
				
				system("PAUSE");
				
				break;
			
			case 3:
				return 0;
			
				
		}
		system("CLS");
	}while(jugadores_iniciados<2);
	
	if(jugadores_iniciados==2)   //Cuando hay dos jugadores con la sesion iniciada empieza la partida
	{
	system("CLS");
	printf("Empieza La Partida: %s Vs %s\n",jugadores[0].jugador,jugadores[1].jugador);
	
	system("PAUSE");
	
	}   //Termina el codigo del menú

    inicio(tablero);

    while (!end)
    {
        // Imprime el tablero
        imprime_tablero(tablero, turno,jugadores[0].jugador,jugadores[1].jugador);

        // Crea un bucle para comprobar el scanf
        do {
            printf("Escribe la posicion [0-5]: ");
            scanf("%d", &posicion);

            if (!(posicion >= 0 && posicion < ANCHO))
            {
                printf("Error en la lectura de posicion.\n");
                next = false;
            }
            else if (tablero[0][posicion] != ' ')
            {
                printf("Esa columna esta llena.\n");
                next = false;
            }
            else
            {
                next = true;
            }
        } while (!next);

        // Añade la ficha al tablero
        mete_ficha(tablero, &posicion, turno % 2, fichas, num_fichas);
        num_fichas++;

        // Comprueba si ha ganado alguien o es el fin
        if (juego_terminado(tablero, turno))
        {
       	
        	if(turno%2==0)
        	printf("GANADOR: %s\n",jugadores[0].jugador);
        	else
        	printf("GANADOR: %s\n",jugadores[1].jugador);
     
            end = true;
        }
        else if (num_fichas == FMAX)
        {
            printf("\n\nHan quedado empate\n");
        }
        else
            // Da paso al siguiente turno
            turno++;
    }


}

void inicio(char tablero[LARGO][ANCHO])
{
    for (int i = 0; i < LARGO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

void imprime_tablero(char tablero[LARGO][ANCHO], int turno,char nombre1[],char nombre2[])
{

    system("CLS");

	if(turno%2==0)
	{
    printf("\n\tTurno del %s jugador(%s)\n\n", jugadores[turno % 2][0], nombre1); 
	}
	else
	{
	 printf("\n\tTurno del %s jugador(%s)\n\n", jugadores[turno % 2][0], nombre2);                                                                                              //Queremos que salga el nombre del primer y el segundo jugador que inicia sesion
    }                                                                                               

    for (int i = 0; i < LARGO; i++)
    {
        printf("\t     ");
        for (int j = 0; j < ANCHO; j++)
        {
            printf("|%c|", tablero[i][j]);
        }
        printf("\n");
    }

    printf("\n\t     ");
    for (int i = 0; i < ANCHO; i++)
    {
        printf(" %i ", i);
    }
    printf("\n\n");
    
    
}

void mete_ficha(char tablero[LARGO][ANCHO], int* pos, int turno, Fichas fichas[FMAX], int num_fichas)
{
    if (*pos >= 0 && *pos < ANCHO)
    {
        for (int i = LARGO - 1; i >= 0; i--) {
            if (tablero[i][*pos] == ' ')
            {
                tablero[i][*pos] = (turno == 0 ? 'R' : 'A');
                inserta_ficha(fichas, num_fichas, *pos, i, (turno % 2) + 1);

                break;
            }
        }
    }

    *pos = 0;
}

void inserta_ficha(Fichas* fichas, int num_fichas, int X, int Y, int num_jugador)
{
    fichas[num_fichas].pos[0] = X;
    fichas[num_fichas].pos[1] = Y;
    fichas[num_fichas].num_jugador = num_jugador;
}

bool juego_terminado(char tablero[LARGO][ANCHO], int turno)
{
    // Horizontal
    for (int i = 0; i < LARGO; i++)
    {
        for (int j = 0; j <= ANCHO - FICHAS_FIN; j++)
        {
            if (
                tablero[i][j] != ' ' &&
                tablero[i][j] == tablero[i][j + 1] &&
                tablero[i][j] == tablero[i][j + 2] &&
                tablero[i][j] == tablero[i][j + 3])
                return true;
        }
    }

    // Vertical
    for (int i = 0; i <= LARGO - FICHAS_FIN; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            if (
                tablero[i][j] != ' ' &&
                tablero[i][j] == tablero[i + 1][j] &&
                tablero[i][j] == tablero[i + 2][j] &&
                tablero[i][j] == tablero[i + 3][j])
                return true;
        }
    }

    // Diagonal Abajo '\'
    for (int i = 0; i <= LARGO - FICHAS_FIN; i++)
    {
        for (int j = 0; j <= ANCHO - FICHAS_FIN; j++)
        {
            if (
                tablero[i][j] != ' ' &&
                tablero[i][j] == tablero[i + 1][j + 1] &&
                tablero[i][j] == tablero[i + 2][j + 2] &&
                tablero[i][j] == tablero[i + 3][j + 3])
                return true;
        }
    }

    // Diagonal Arriba '/'
    for (int i = LARGO - FICHAS_FIN; i < LARGO; i++)
    {
        for (int j = ANCHO - FICHAS_FIN; j < ANCHO; j++)
        {
            if (
                tablero[i][j] != ' ' &&
                tablero[i][j] == tablero[i + 1][j - 1] &&
                tablero[i][j] == tablero[i + 2][j - 2] &&
                tablero[i][j] == tablero[i + 3][j - 3])
                return true;
        }
    }

    return false;
}


