#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void primer_menu();
int el_switch(int ID[7], char nombre[7][100],  char descripcion[7][1000], int cantidad[7], float precio[7]);
void MENUver_productos(int ID[7], char nombre[7][100],char descripcion[7][1000], int cantidad[7], float precio[7]);
void agregar_productos(int ID[7], char nombre[7][100],char descripcion[7][1000], int cantidad[7], float precio[7]);
void modificar_productos(int ID[7], char nombre[7][100],char descripcion[7][1000], int cantidad[7], float precio[7]);






int main() {
    int ID[7] = {1357, 2468, 3579, 4680, 1234, 0, 0};
    char nombre[7][100] = {"BATMAN", "SUPERMAN", "SPIDERMAN", "FLASH", "LINTERNA VERDE", ".", "."};
    char descripcion[7][1000] = {"El Caballero Oscuro de Gotham City", "El Hombre de Acero", "El Hombre Araña", "El Velocista Escarlata", "Miembro de los Green Lantern Corps", ".", "."};
    int cantidad[7] = {10, 8, 12, 6, 9, 0, 0};
    float precio[7] = {15.99, 14.99, 12.99, 16.99, 13.99, 0, 0};
    

    int FINAL = 0;
    do {

    FINAL = el_switch(ID, nombre, descripcion, cantidad, precio);

    } while (FINAL == 1);

    return 0;
}


int el_switch(int ID[7], char nombre[7][100],  char descripcion[7][1000], int cantidad[7], float precio[7]){

int FINAL = 1;
        primer_menu();
        int opcion;
        printf("\n");        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                MENUver_productos(ID, nombre, descripcion, cantidad, precio);
                break;

            case 2:
                agregar_productos(ID, nombre, descripcion, cantidad, precio);
                break;
            case 3:
                modificar_productos(ID, nombre, descripcion, cantidad, precio);
                break;
            
            default:
                FINAL = 0;
                break;
        }


return FINAL;
}



void primer_menu() {

printf("\n\n\tMENU\n\t");
printf("\n\t1._ VER PRODUCTO\t");
printf("\n\t2._ INGRESO PRODUCTO\t");
printf("\n\t3._ MODIFICACION PRODUCTO\t");
printf("\n\t4._ SALIR\t");

}

void MENUver_productos(int ID[7], char nombre[7][100],  char descripcion[7][1000], int cantidad[7], float precio[7]) {
    printf("Codigo\t\tNombre\t\t\t\tdescripcion\t\t\t\tCantidad\t\t\tPrecio\n");
    for (int i = 0; i < 7; i++) {
        printf("%d\t\t%s\t\t\t\t%s\t\t\t\t%i\t\t\t%.2f\n", ID[i], nombre[i], descripcion[i], cantidad[i], precio[i]);
    }
}

void agregar_productos(int ID[7], char nombre[7][100],  char descripcion[7][1000], int cantidad[7], float precio[7]) {
    for (int i = 0; i < 7; i++) {
        if (ID[i] == 0) {
            printf("Ingresar id: ");            scanf("%d", &ID[i]);
            printf("Ingresar nombre: ");            scanf(" %[^\n]", nombre[i]);
            printf("Ingresar descripcion: ");            scanf(" %[^\n]", descripcion[i]);
            printf("Ingresar cantidad: ");            scanf("%d", &cantidad[i]);
            printf("Ingresar precio: ");            scanf("%f", &precio[i]);            
            break;
        }
    }
}

void modificar_productos(int ID[7], char nombre[7][100],  char descripcion[7][1000], int cantidad[7], float precio[7]) {
    int codigo;
    int opcion;


printf("\n\n\tDeseas modificar o eliminar el producto?\n\t");
printf("\n\n\t1.-MODIFICAR\n\t");
printf("\n\n\t2.-ELIMINAR\n\t");

scanf("%i", &opcion);
    switch(opcion){

case 1:

    printf("Por favor introduce el ID del producto\n");    scanf("%i",&codigo);

    for (int i = 0; i < 7; i++) {
        if (ID[i] == codigo) {

            printf("Ingrese la cantidad: ");            scanf("%i", &cantidad[i]);
            printf("Ingrese la precio: ");            scanf("%f", &precio[i]);
            break;
            
        }
    }
    break;


case 2: 

printf("Por favor introduce el ID del producto\n");    scanf("%i",&codigo);

for (int i = 0; i < 7; i++) {
        if (ID[i] == codigo) {
            ID[i]=0;
            strcpy(nombre[i],".");
            strcpy(descripcion[i],".");
            cantidad[i]=0;
            precio[i]=0;
            break;
}
break;


default: printf("por favor ingresa una opcion disponible (1 o 2)");

    }
}
}


