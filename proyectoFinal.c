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
int contador = 10; //Variable que mide si esta llena o no la base de datos
char nulo[] = "NULL";


int main(){
	setlocale(LC_ALL, "");
	//La pantalla va a tener un estilo inicial de fondo blanco y texto negro
	system("color f0");
	//La pantalla va a tener 
	system("mode con: cols=100 lines=30");
	srand(time(NULL));
	generarSalarios();
	generarClaves();
	generarNombres();
	menu();
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
	system("cls");
	//menú principal
		int o = 0;
	int i = -1;
	
	while(o != 7){
	system("cls");
		printf("\n\t\tBienvenido al menu\n");
		printf("\n\t1 Mostrar todos los contactos:\n ");//Los tres registros con la info de el trabajador
		printf("\n\t2 Buscar registro: \n");//opcion de nombre o clave
		printf("\n\t3 Ordenar alfabeticamente por Nombre: \n");
		printf("\n\t4 Insertar nuevos registros: \n");
		printf("\n\t5 Eliminar un registro: \n");
		printf("\n\t6 Modificar: \n");//La clave, el nombre o el salario
		printf("\n\t7 Salir\n");
	
	printf("\n\t Que opcion desea elegir: ");
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
			gotoxy(40, 1);
			printf("Base de datos");
			imprimirTabla();
			imprimirRegistros();
			printf("\n\n\t");
			system("pause");
			system("cls");
		}
		if(o == 2){
			system("cls");
			while(i !=0){
				printf("\n\t1 Buscar por nombre.\n");
				printf("\n\t2 Buscar por clave.\n");
				printf("\n\t0 Regresar al menu.\n");
				printf("\n\t¿Como desea buscar el registro? ");
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
			insertarRegistros();
		}
		if(o == 5){
			system("cls");
			//Eliminar un registro
			eliminarRegistros();
			}
		if(o == 6){
			system("cls");
			while(i != 0){
				printf("\n\t1 Modificar clave.");
				printf("\n\t2 Modificar nombre.");
				printf("\n\t3 Modificar el salario.");
				printf("\n\t0 Regresar al menu principal");
				printf("\n\t\t¿Que desea modoficar? ");
				scanf("%d", &i);
				
				if(i != 1,2,3,0){
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
		if(strcmp(nombresGenerados[i], "NULL") != 0){//EN eliminar un registro, se reemplazan por 0 o NULL y esta condicion evita que se impriman
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

}
//

void buscarRegistro(){
	
}
//
void ordenarRegistros(){
	
}
//
void insertarRegistros(){
	int claveInsertada = 0;//VARIABLES DONDE SE GUARDARAN LOS NUEVOS VALORES
	char nombreInsertado [100];
	float nuevoSalario = 0;
    if(contador > 9){//VERIFICA SI YA ESTA LLENA LA BASE DE DATOS
        printf("\n\tBASE DE DATOS (%d) LLENA, ELIMINA UN REGISTRO ANTES\n",contador);
        system("pause");
    } else {
        // Insertar loz nuevos registro
        do{//La clave lleva la condicion de ser solo 4 numeros
            printf("\n\tIngrese la clave del nuevo registro (4 digitos): ");
        	scanf("%d", &claveInsertada);	
        	if(claveInsertada < 1000 || claveInsertada > 9999){
        		printf("\n\tERROR SOLO PUEDEN SER 4 DIGITOS"); //VALIDAMOS QUE SEAN NUMEROS DE 4 DIGITOS
        	}
        }while(claveInsertada < 1000 || claveInsertada > 9999);

        printf("\n\tIngrese el nuevo nombre (con mayusculas en las primeras letras y espacios): ");
        fflush(stdin);
        gets(nombreInsertado);
        printf("\n\tIngrese el nuevo salario: ");
        scanf("%f",&nuevoSalario);
        //REEMPLAZAMOS LAS VARIABLES DONDE ESTE EL VALOR ELIMINADO Y LOS IDENTIFICAMOS MEDIANTE UN FOR Y LOCALIANDO AL NULL
        for(i = 0; i < 10; i++){
        	if(strcmp(nombresGenerados[i], nulo) == 0){//nulo es NULL lo que identifica que un arreglo fue eliminado
        		clave[i] = claveInsertada;
        		strcpy(nombresGenerados[i], nombreInsertado);
        		salario[i] = nuevoSalario;
        	}
        }



        // Incrementar el contador para llenar la base de datos
        contador++;

        printf("\nRegistro insertado con éxito.\n");
        system("pause");
        menu();
    }
}

//
void eliminarRegistros(){
	system("cls");
	int op = 0;//Variable opciones del switch
	//MENU 
	printf("\n\t¿Cómo desea eliminar el registro?");
	printf("\n\t(0)Eliminar por clave");
	printf("\n\t(1)Eliminar por nombre");
	printf("\n\t(2)Regresar al menu");
	printf("\n\tIngrese una opcion: ");
	scanf("%d",&op);
	
	switch (op){//Switch case para acceder a las distintas opciones del menu
	//ELIMINAR POR CLAVE
		case 0:{
			int claveEliminada = 0; //Variable donde se guardara la variable que deseas eliminar
			int indicador = 0; //Variable que indica si se encontro o no la clave que deseas eliminar
			int n = 0; //Variable que valide la eleccion correcta de mostrar o no la tabla
			system("cls");
			printf("\n\t(1)Mostrar tabla");
			printf("\n\t(2)No mostrar tabla");
			printf("\n\tSeleccione una opción: ");
			scanf("%d",&n);//Se lee la variable
			
			while(n < 1 || n > 2){//condicion que valide una opcion correcta del menu si se elegio un numero incorrecto
				printf("\n\tOPCION NO VALIDA, VUELVA A ELEGIR: ");
				scanf("%d",&n);
			}
			//mostrando la tabla
			if(n == 1){//Condicion, si se elige 1 mostrara la tabla
				while(indicador == 0){//Ciclo while, se repite hasta que introduzcas una clave valida
					system("cls");
					imprimirTabla();
					imprimirRegistros();
					printf("\n\tIngrese la clave del registro que quiera eliminar: ");
					scanf("%d",&claveEliminada);
					for(i = 0; i < 10; i++){//Ciclo for para encontrar la clave que se desea eliminar
						if(clave[i] == claveEliminada){
							clave[i] = 0;
							strcpy(nombresGenerados[i],nulo);//Copiar en la cadena de nombres, la cadena nulo para eliminar el registro
							indicador = 99;//Se iguala a 99 para que salga del ciclo while
						}
					}
					if (indicador != 99){
						printf("\n\tClave no encontrada vuelve a intentarlo.");
						printf("\n\tTeclea (3) para regresar.");
						scanf("%d",&indicador);
						if(indicador == 3){//Si presiona 3 se guarda en indicador y se sale del programa
							eliminarRegistros();//Regresamos al menu de eliminar registros
						}
					}
										
				}
				contador--;
				printf("\n\tRegistro eliminado con exito.\n");//regresar al completar la eliminacion
				system("pause");
				menu();
				//SIN MOSTRAR LA TABLA
			}else if (n == 2){//si se elige 2 no se mostrara la tabla
				system("cls");
				while(indicador == 0){//Ciclo while, se repite hasta que introduzcas una clave valida
					system("cls");
					printf("\n\tIngrese la clave del registro que quiera eliminar: ");
					scanf("%d",&claveEliminada);
					for(i = 0; i < 10; i++){//Ciclo for para encontrar la clave que se desea eliminar
						if(clave[i] == claveEliminada){
							clave[i] = 0;
							strcpy(nombresGenerados[i],nulo);//Copiar en la cadena de nombres, la cadena nulo para eliminar el registro
							indicador = 99;//Se iguala a 99 para que salga del ciclo while
						}
					}
					if (indicador != 99){
						printf("\n\tClave no encontrada vuelve a intentarlo.");
						printf("\n\tTeclea (3) para regresar.");
						scanf("%d",&indicador);
						if(indicador == 3){//Si presiona 3 se guarda en indicador y se sale del programa
							eliminarRegistros();//Regresamos al menu de eliminar registros
						}
					}
										
				}
				contador--;
				printf("\n\tRegistro eliminado con exito.\n");//Mensaje de ejecucion exitosa
				system("cls");
				break;
			}

		}
		//ELIMINAR POR NOMBRE
		case 1:{
			int indicador = 0; //Variable que indica si se encontro o no la clave que deseas eliminar
			char nombreEliminado[99]; 
			int n = 0; //Variable que valide la eleccion correcta de mostrar o no la tabla
			system("cls");
			printf("\n\t(1)Mostrar tabla");
			printf("\n\t(2)No mostrar tabla");
			printf("\n\tSeleccione una opción: ");
			scanf("%d",&n);//Se lee la variable
			
			while(n < 1 || n > 2){//condicion que valide una opcion correcta del menu si se elegio un numero incorrecto
				printf("\n\tOPCION NO VALIDA, VUELVA A ELEGIR: ");
				scanf("%d",&n);
			}
			if(n == 1){//Condicion, si se elige 1 mostrara la tabla
			while(indicador == 0){
				system("cls");
				imprimirTabla();//Imprimimos la tabla
				imprimirRegistros();
				printf("\n\tIngrese el nombre del registro que quiera eliminar: ");
				fflush(stdin);//Evitar error al limpiar buffer
				gets(nombreEliminado);//obtenemos el nombre que desea eliminar
				for(i = 0; i < 10; i++){//Buscamos con un ciclo for el nombre que desea eliminar
					if(strcmp(strlwr(nombresGenerados[i]),strlwr(nombreEliminado)) == 0){//usamos lwr para convertrir a minusculas
						strcpy(nombresGenerados[i],nulo);//Copiar en la cadena de nombres, la cadena nulo para eliminar el registro
						indicador = 99; //Se iguala a 99 para salir del while
					}
				}
				if (indicador != 99){
					printf("\n\tClave no encontrada vuelve a intentarlo.");
					printf("\n\tTeclea (3) para regresar.");
					scanf("%d",&indicador);
					if(indicador == 3){//Si presiona 3 se guarda en indicador y se sale del programa
						eliminarRegistros();
					}
				}				
			}
			contador--;
			printf("\n\tRegistro eliminado con exito.\n");//REGRESAR UNA VEZ SEA ELIMINADA
			system("pause");
			menu();
				
			}else if (n == 2){//si se elige 2 no se mostrara la tabla
				while(indicador == 0){
					system("cls");
					printf("\n\tIngrese el nombre del registro que quiera eliminar: ");
					fflush(stdin);//Evitar error al limpiar buffer
					gets(nombreEliminado);//obtenemos el nombre que desea eliminar
					for(i = 0; i < 10; i++){//Buscamos con un ciclo for el nombre que desea eliminar
						if(strcmp(strlwr(nombresGenerados[i]),strlwr(nombreEliminado)) == 0){//Usamos strlwr para convertir a minusculas y que sea igual
						strcpy(nombresGenerados[i],nulo);//Copiar en la cadena de nombres, la cadena nulo para eliminar el registro
						indicador = 99; //Se iguala a 99 para salir del while
						}
					}
					if (indicador != 99){
						printf("\n\tClave no encontrada vuelve a intentarlo.");
						printf("\n\tTeclea (3) para regresar.");
						scanf("%d",&indicador);
						if(indicador == 3){//Si presiona 3 se guarda en indicador y se sale del programa
							eliminarRegistros();
						}
					}				
				}
				contador--;
				printf("\n\tRegistro eliminado con exito.\n");//REGRESAR AL MENU CUANDO SEA ELIMINADO
				system("pause");
				menu();
			}
			

		}
		case 2:{//Caso donde se regresa al menu
			printf("\n\tRegresando al Menu...\n");
			system("pause");
			menu();
		}
		default:{//Si se ingresa una opcion no valida
			printf("\n\tOPCION NO VALIDA\n");
			system("pause");
			eliminarRegistros();
		}
	}

}
	

//
void modificarRegisro(){
	
}
