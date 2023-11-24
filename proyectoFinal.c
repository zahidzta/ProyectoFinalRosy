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
void modificarRegistro();//Javier
void gotoxy(int x, int y);
void menu();

// Vectores universales que guardan los nombres y los apellidos que se van a utilizar
char nombres[10][20] = {"Zahid", "Abel", "Javier", "Diego", "Alejandro", "Leonardo", "Daniel", "Maria", "Julieta", "Elisa"};
char apellidos[10][20] = {"Rios", "Duron", "Garcia", "Tafoya", "Jimenez", "Hernandez", "Esparza", "Esquivel", "Guerrero", "Carrasco"};
// Matriz donde se van a guardar los nombres generados
char nombresGenerados[10][50];
// Vector donde se van a guardar las claves generadas
int clave[10];
// Vector donde se van a guardar los salarios generados
float salario[10];

int i;

int main() {
    setlocale(LC_ALL, "");
    // La pantalla va a tener un estilo inicial de fondo blanco y texto negro
    system("color f0");
    // La pantalla va a tener 
    system("mode con: cols=100 lines=30");
    srand(time(NULL));
    generarSalarios();
    generarClaves();
    generarNombres();
    menu();
    return 0;
}

// Función para utilizar gotoxy (mover el cursor en la pantalla)
void gotoxy(int x, int y) {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenadas;
    coordenadas.X = x;
    coordenadas.Y = y;
    SetConsoleCursorPosition(consola, coordenadas);
}

void menu() {
    system("cls");
    // menú principal
    int o = 0;
    int opcionSubMenu = -1;

    while (o != 7) {
        printf("\n\t\tBienvenido al menu\n");
        printf("\n\t1 Mostrar todos los contactos:\n ");// Los tres registros con la info de el trabajador
        printf("\n\t2 Buscar registro: \n");// opcion de nombre o clave
        printf("\n\t3 Ordenar alfabéticamente por Nombre: \n");
        printf("\n\t4 Insertar nuevos registros: \n");
        printf("\n\t5 Eliminar un registro: \n");
        printf("\n\t6 Modificar: \n");// La clave, el nombre o el salario
        printf("\n\t7 Salir\n");

        printf("\n\t Que opción desea elegir: ");
        scanf("%d", &o);
        
        if (o < 1 || o > 7) {
            system("cls");
            printf("\n\tIngrese una opción válida\n");
        }

        switch (o) {
            case 1:
                system("cls");
                gotoxy(40, 1);
                printf("Base de datos");
                imprimirTabla();
                imprimirRegistros();
                printf("\n\n\t");
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                while (opcionSubMenu != 0) {
                    printf("\n\t1 Buscar por nombre.\n");
                    printf("\n\t2 Buscar por clave.\n");
                    printf("\n\t0 Regresar al menú.\n");
                    printf("\n\t¿Cómo desea buscar el registro? ");
                    scanf("%d", &opcionSubMenu);

                    if (opcionSubMenu < 0 || opcionSubMenu > 2) {
                        system("cls");
                        printf("\n\tIngrese una opción válida\n");
                    }

                    if (opcionSubMenu == 1) {
                        system("cls");
                        // Buscar por nombre
                    } else if (opcionSubMenu == 2) {
                        system("cls");
                        // Buscar por clave
                    } else if (opcionSubMenu == 0) {
                        system("cls");
                        break;
                    }
                }
                break;

            case 3:
                system("cls");
                // Ordenar alfabéticamente por nombre
                break;

            case 4:
                system("cls");
                // Insertar nuevos registros
                insertarRegistros();
                break;

            case 5:
                system("cls");
                // Eliminar un registro
                eliminarRegistros();
                break;

            case 6:
                system("cls");
                while (opcionSubMenu != 0) {
                    printf("\n\t1 Modificar clave.");
                    printf("\n\t2 Modificar nombre.");
                    printf("\n\t3 Modificar el salario.");
                    printf("\n\t0 Regresar al menú principal");
                    printf("\n\t\t¿Qué desea modificar? ");
                    scanf("%d", &opcionSubMenu);

                    if (opcionSubMenu < 0 || opcionSubMenu > 3) {
                        system("cls");
                        printf("\n\tIngrese una opción válida\n");
                    }

                    if (opcionSubMenu == 1) {
                        system("cls");
                        // Modificar la clave
                    } else if (opcionSubMenu == 2) {
                        system("cls");
                        // Modificar clave
                    } else if (opcionSubMenu == 3) {
                        system("cls");
                        // Modificar salario
                    } else if (opcionSubMenu == 0) {
                        system("cls");
                        break;
                    }
                }
                break;

            case 7:
                system("cls");
                printf("\n\tGracias por usar nuestro programa\n");
                exit(0);
                break;

            default:
                break;
        }
    }
    //restablecer i
    i = -1;
    printf("Menu");
}

void generarSalarios() {
    for (i = 0; i < 10; i++) {
        salario[i] = rand() % 14001 + 6000;
    }
}

void generarClaves() {
    for (i = 0; i < 10; i++) {
        clave[i] = rand() % 9000 + 1000;
    }
}

void generarNombres() {
    int numRandom;
    for (i = 0; i < 10; i++) {
        numRandom = rand() % 10;
        strcat(nombresGenerados[i], nombres[numRandom]);
        strcat(nombresGenerados[i], " ");
        numRandom = rand() % 10;
        strcat(nombresGenerados[i], apellidos[numRandom]);
        strcat(nombresGenerados[i], " ");
        numRandom = rand() % 10;
        strcat(nombresGenerados[i], apellidos[numRandom]);
    }
}

void imprimirTabla() {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    color(consola, 112);
    gotoxy(15, 3);
    printf("CLAVE");
    gotoxy(43, 3);
    printf("NOMBRE");
    gotoxy(72, 3);
    printf("SALARIO");
    color(consola, 240);
    for (i = 0; i < 80; i++) {
        gotoxy(10 + i, 4);
        printf("_");
    }
}

void imprimirRegistros() {
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    for (i = 0; i < 10; i++) {
        gotoxy(15, i + 5);
        color(consola, 248);
        printf("%d", clave[i]);
        color(consola, 240);
        gotoxy(27, i + 5);
        printf("|");
        gotoxy(35, i + 5);
        printf("%s", nombresGenerados[i]);
        gotoxy(70, i + 5);
        gotoxy(68, i + 5);
        printf("|");
        printf("$%.2f ", salario[i]);
        gotoxy(85, i + 5);
        printf("MXN");
    }
}

void buscarRegistro() {

}

void ordenarRegistros() {

}

void insertarRegistros() {
    int opcion = 0;

    if (i >= 10) {
        printf("\n\tNO PUEDES INSERTAR MAS REGISTROS (MAX 10), DEBES ELIMINAR UNO");
        system("pause");
        menu();
        return;
    }

    printf("\n\tHas seleccionado la opción de insertar un registro.");
    printf("\n\tInsertar registro (presiona 1) ");
    printf("\n\tVolver a menú (presiona 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        system("cls");
        int n = 0;
        while (n != 3) {
            printf("\n\t¿Mostrar tabla de registros? ");
            printf("(1) Si.");
            printf("(2) No.");
            printf("\n\t");
            scanf("%d", &n);

            if (n == 1) {
                imprimirTabla();
                imprimirRegistros();
                printf("\n\tIngrese la nueva clave: ");
                scanf("%d", &clave[i]);

                printf("\n\tIngrese el nuevo nombre: ");
                fflush(stdin);
                fgets(nombresGenerados[i], sizeof(nombresGenerados[i]), stdin);
                nombresGenerados[i][strlen(nombresGenerados[i]) - 1] = '\0';

                printf("\n\tIngrese el nuevo salario: ");
                scanf("%f", &salario[i]);
            } else if (n == 2) {
                printf("\n\tIngrese la nueva clave: ");
                scanf("%d", &clave[i]);

                printf("\n\tIngrese el nuevo nombre: ");
                fflush(stdin);
                fgets(nombresGenerados[i], sizeof(nombresGenerados[i]), stdin);
                nombresGenerados[i][strlen(nombresGenerados[i]) - 1] = '\0';

                printf("\n\tIngrese el nuevo salario: ");
                scanf("%f", &salario[i]);
            } else {
                printf("\n\tOpción inválida");
                system("pause");
            }
        }
    } else if (opcion == 2) {
        menu();
    } else {
        system("cls");
        printf("\n\tOpción no válida");
        system("pause");
        menu();
    }
}

void eliminarRegistros() {
	int j = 0, k = 0;
	int opcion;
    printf("\n\t¿Cómo desea buscar el registro a eliminar?");
    printf("\n\t1. Por clave.");
    printf("\n\t2. Por nombre.");
    printf("\n\t0. Regresar al menú principal.");
    printf("\n\tOpción: ");
    scanf("%d", &opcion);

    if (opcion == 0) {
        menu();
        return;
    }

    int indice = -1;

    if (opcion == 1) {
        system("cls");
        imprimirTabla();
        imprimirRegistros();
        int claveEliminar;
        printf("\n\tIngrese la clave del registro a eliminar: ");
        scanf("%d", &claveEliminar);

        for (j = 0; j < i; j++) {
            if (clave[j] == claveEliminar) {
                indice = j;
                break;
            }
        }
    } else if (opcion == 2) {
        system("cls");
        imprimirTabla();
        imprimirRegistros();
        char nombreEliminar[50];
        printf("\n\tIngrese el nombre del registro a eliminar: ");
        fflush(stdin);
        fgets(nombreEliminar, sizeof(nombreEliminar), stdin);
        nombreEliminar[strlen(nombreEliminar) - 1] = '\0';

        for (j = 0; j < i; j++) {
            if (strcmp(nombresGenerados[j], nombreEliminar) == 0) {
                indice = j;
                break;
            }
        }
    }

    if (indice != -1) {
        // Eliminar el registro de los vectores
        for (k = indice; k < i - 1; k++) {
            clave[k] = clave[k + 1];
            strcpy(nombresGenerados[k], nombresGenerados[k + 1]);
            salario[k] = salario[k + 1];
        }

        i--;  // Decrementar el contador de registros después de eliminar uno

        printf("\n\tRegistro eliminado exitosamente.\n");
    } else {
        printf("\n\tNo se encontró un registro con la clave o nombre proporcionado.\n");
    }

    system("pause");
    menu();
}

void modificarRegistro() {

}
