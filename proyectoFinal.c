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
