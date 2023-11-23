#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>

#define color SetConsoleTextAttribute

void generarNombres();
void generarClaves();
void generarSalarios();
void imprimirTabla();
void imprimirRegistros();
void buscarRegistro();//zahid
void ordenarRegistros();//zahid
void insertarRegistros();//Abel
void eliminarRegistros();//Abel
void modificarRegisro();//Javi
void gotoxy(int x, int y);
void menu();

//Vectores universales que guardan los nombres y los apellido que se van a utilizar
char nombres[10][20] = {"Zahid", "Abel", "Javier", "Diego", "Alejandro", "Leonardo", "Daniel", "Maria", "Julieta", "Elisa"};
char apellidos[10][20] = {"Rios", "Duron", "Garcia", "Tafoya", "Jimenez", "Hernandez", "Esparza", "Esquivel", "Guerrero", "Carrasco"};
//Matriz donde se van a guardar los nombres generados
char nombresGenerados[10][50];
//Vector donde se van a guardar las claves generadas
int clave[10];
//Vector donde se van a guardar los salarios generados
float salario[10];

int i;

int main(){
	setlocale(LC_ALL, "");
	//La pantalla va a tener un estilo inicial de fondo blanco y texto negro
	system("color f0");
	//La pantalla va a tener 
	system("mode con: cols=100 lines=30");
	srand(time(NULL));
	menu();
	gotoxy(40, 1);
	printf("Base de datos");
	generarSalarios();
	generarClaves();
	generarNombres();
	imprimirTabla();
	imprimirRegistros();
	return 0;
}
//función para utilizar gotoxy(mover el cursor en la pantalla)
void gotoxy(int x, int y){
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(consola,coordenadas);
}

void menu(){
	//menú principal
		int o = 0;
	int i = -1;
	
	while(o != 7){
			printf("\n\t\tBeinvenido al menu\n");
	printf("\n\t1 Mostrar todos los contactos:\n ");//Los tres registros con la info de el trabajador
	printf("\n\t2 Buscar registro: \n");//opcion de nombre o clave
	printf("\n\t3 Ordenar alfabeticamente por Nombre: \n");
	printf("\n\t4 Insertar nuevos registros: \n");
	printf("\n\t5 Eliminar un registro: \n");
	printf("\n\t6 Modificar: \n");//La clave, el nombre o el salario
	printf("\n\t7 Salir\n");
	
	printf("\n\t Que opcion desea elegir: ");
	fflush(stdin);
	scanf("%d", &o);
		if(o != 1, o!= 2, o != 3, o!= 4, o != 5, o != 6, o!= 7){
			system("cls");
			printf("\n\tIngrese una opcion valida\n");
		}
		if(o == 7){
			system("cls");
			printf("\n\tGracias por usar nuestro programa\n");
			exit(0);
		}
		if(o == 1){
			system("cls");
			//Trabajadores con sus datos de informacion
		}
		if(o == 2){
			system("cls");
			while(i !=0){
				printf("\n\t1 Buscar por nombre.\n");
				printf("\n\t2 Buscar por clave.\n");
				printf("\n\t0 Regresar al menu.\n");
				printf("\n\t¿Como desea buscar el registro? ");
				fflush(stdin);
				scanf("%d", &i);
				
				if(i != 1 & i != 2, i!= 0){
					system("cls");
					printf("\n\t Ingrese una opcion valida\n");
				}
				if(i == 1){
					system("cls");
					//Buscar por nombre
				}
				if(i== 2){
					system("cls");
					//Buscar por clave
				}
				if(i == 0){
					system("cls");
					menu();
					//Regresar al menu
				}
			}
		}	
		if(o == 3){
			system("cls");
			//Ordenar por orden alfabetico el nombre
		}
		if (o == 4){
			system("cls");
			//Insertar nuevos registros
		}
		if(o == 5){
			system("cls");
			//Eliminar un registro
			}
		if(o == 6){
			system("cls");
			while(i != 0){
				printf("\n\t1 Modificar clave.");
				printf("\n\t2 Modificar nombre.");
				printf("\n\t3 Modificar el salario.");
				printf("\n\t0 Regresar al menu principal");
				printf("\n\t\t¿Que desea modoficar? ");
				fflush(stdin);
				scanf("%d", &i);
				
				if(i != 1, i != 2, i != 3,i != 0){
					system("cls");
					printf("\n\tIngrese una opcion valida\n");
				}
				if(i == 1){
					system("cls");
					//Modificar la clave
				}
				if(i == 2){
					system("cls");
					//Modificar clave
				}
				if(i == 3){
					system("cls");
					//Modificar salario
				}
				if(i == 0){//Regresar al menu
					system("cls");
					menu();
				}
			}
		}
	}
	printf("Menu");
}

void generarSalarios(){
	for(i = 0; i < 10; i++){
		//Los salarios que se pueden generar van de los 6000 a 20000
		salario[i] = rand() % 14001 + 6000;
	}
}

void generarClaves(){
	for(i = 0; i < 10; i++){
		//Las claves que se pueden generar van del 1000 al 9999
		clave[i] = rand() % 9000 + 1000;
	}
}

void generarNombres(){
	//variable para guardar un número aleatorio
	int numRandom;
	for(i = 0; i < 10; i++){
		numRandom = rand() % 10;
		//se concatena el nombre que se eligió aleatoriamente al valor de la matriz en la posición i
		strcat(nombresGenerados[i], nombres[numRandom]);
		//se le agrega un espacio a la cadena
		strcat(nombresGenerados[i], " ");
		numRandom = rand() % 10;
		//se concatena el apellido 1 que se eligió aleatoriamente al valor de la matriz en la posición i
		strcat(nombresGenerados[i], apellidos[numRandom]);
		//se le agrega un espacio a la cadena
		strcat(nombresGenerados[i], " ");
		numRandom = rand() % 10;
		//se concatena el apellido 2 que se eligió aleatoriamente al valor de la matriz en la posición i
		strcat(nombresGenerados[i], apellidos[numRandom]);
	}
}
//Función para imprimir la tabla donde se van a mostrar los registros
void imprimirTabla(){
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	//Estilo fondo gris y texto negro para los titulos de las columnas
	color(consola, 112);
	//Con ayuda de gotoxy se colocan los titulos de las columnas
	gotoxy(15, 3);
	printf("CLAVE");
	gotoxy(43, 3);
	printf("NOMBRE");
	gotoxy(72, 3);
	printf("SALARIO");
	//Se regresa al estilo del texto original(fondo blanco texto negro)
	color(consola, 240);
	//Se crea una barra inferior para dividir la tabla
	for(i = 0; i < 80; i++){
		gotoxy(10 + i, 4);
		printf("_");
	}
}

//Función para imprimir los registros
void imprimirRegistros(){
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	for(i = 0; i < 10; i++){
		//Se imprimen las claves
		gotoxy(15, i + 5);
		color(consola, 248);
		printf("%d", clave[i]);
		color(consola, 240);
		gotoxy(27, i + 5);
		//Linea para dividir las claves de los nombres
		printf("|");
		gotoxy(35, i + 5);
		//Se imprimen los nombres
		printf("%s", nombresGenerados[i]);
		gotoxy(70, i + 5);
		gotoxy(68, i + 5);
		//Linea para dividir los nombres de los salarios
		printf("|");
		//Se imprimen los salarios
		printf("$%.2f ", salario[i]);
		gotoxy(85, i + 5);
		printf("MXN");
	}
}
//

void buscarRegistro(){
	
}
//
void ordenarRegistros(){
	
}
//
void insertarRegistros(){
	
}
//
void eliminarRegistros(){
	
}
//
void modificarRegisro(){
	
}
