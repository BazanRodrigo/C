#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE*bd;

char cas[10], ag = 0, cot = 0, cache[10], clave_baja[10], nombre_baja[10], nuevo_clave[10];

char nuevo_nombre[10], nuevo_medida[10], nuevo_precio[10];

int continuar = 1, found = 0, r, d = 0, palabrasdeabajo = 0, palabrasdearriba = 0, pt = 20, respuesta_nuevo, cont = 0, resp_menu = -1;
int z,i,f ,a;
float valoru, subt, cant;

struct producto {
    int bool;
    char*clave[10];
    char nombre[20];
    char medida[10];
    char precio_u[5];
} pp[20];

int rellenador(void) {
    for ( z = 0; z < 20; z++) {
        pp[z].bool = 1;
        fscanf(bd, "%s", &pp[z].clave);
        fscanf(bd, "%s", &pp[z].nombre);
        fscanf(bd, "%s", &pp[z].medida);
        fscanf(bd, "%s", &pp[z].precio_u);
        if (feof(bd) != 0)break;
    }
}

int mostrador(void) {
    for (i = 0; i <= pt; i++) {
        if (pp[i].bool != 0 && pp[i].bool != 2) {
            printf("%s ", &pp[i].clave);
            printf("%s ", &pp[i].nombre);
            printf("%s ", &pp[i].medida);
            printf("%s \n", &pp[i].precio_u);
        }
    }
}

int busqueda_clave(void) {
    found = 0;
    printf("Si llegas a poner una clave repetida, se mostrara el producto en cuetsion \n");
    printf("Digita la clave, recuerda que A!=a \n");
    scanf("%s", &cas);
    for (z = 0; z < pt; z++) {
        if ((strcmp(cas, pp[z].clave)) == 0) {
            found = 1;
            d = z;
            if (found == 1) printf("\nProducto %s %s %s %s encontrado \n", &pp[z].clave, &pp[z].nombre, &pp[z].medida, &pp[z].precio_u);
        }
    }
    if (found != 1) {
        pt++;
        printf("No se encontro un producto con clave %s", &cas);
        strcpy(pp[pt].clave, cas);

    }
}

int busqueda_nombre(void) {
    printf("Si llegas a poner un nombre repetido, se mostrara el producto en cuetsion \n");
    printf("Digita el nombre, recuerda que A=a \n");
    scanf("%s", &pp[pt].nombre);
    for (z = 0; z < 20; z++) {
        if (strcmp(pp[pt].nombre, pp[z].nombre) == 0) {
            found = 1;
            printf("\nProducto %s %s %s %s encontrado \n", &pp[z].clave, &pp[z].nombre, &pp[z].medida, &pp[z].precio_u);
            d = z;
            return 1;
        }
    }
    return 0;
}

int edit(void) {
    pt++;
    busqueda_clave();

    if (pp[pt].bool == 2)return 1;
    busqueda_nombre();
    if (pp[pt].bool == 2)return 1;
    fprintf(bd, "%s ", &pp[pt].clave);
    fprintf(bd, "%s ", &pp[pt].nombre);
    printf("ingresa la medida de %s %s\n", &pp[pt].clave, &pp[pt].nombre);
    scanf("%s", &pp[pt].medida);
    fprintf(bd, "%s", &pp[pt].medida);
    printf("ingresa el precio de %s %s %s\n", &pp[pt].clave, &pp[pt].nombre, &pp[pt].medida);
    scanf("%s", &pp[pt].precio_u);
    fprintf(bd, "%s \n", &pp[pt].precio_u);
    fprintf(bd, "\n");
    printf("Se agrego Satisfactoriamente %s %s %s %s \n", &pp[pt].clave, &pp[pt].nombre, &pp[pt].medida, &pp[pt].precio_u);
    pp[pt].bool = 1;
    return 0;
}

int baja(void) {
    int op_baja;
    printf("¿De que manera deseas buscar el producto en cuestion? \n");
    printf("Por clave................[1]\n");
    printf("Por nombre...............[2]\n");
    scanf("%d", &op_baja);
    while (op_baja != 1 && op_baja != 2) {
        printf("Respuesta incorrecta");
        printf("¿De que manera deseas buscar el producto en cuestion? \n");
        scanf("%d", op_baja);
        printf("Por clave................[1]\n");
        printf("Por nombre...............[2]\n");
    }
    if (op_baja == 1) {
        busqueda_clave();
        if (found == 1) {
            pp[d].bool = 0;
            printf("\nProducto %s %s %s %s eliminado \n\n", &pp[d].clave, &pp[d].nombre, &pp[d].medida, &pp[d].precio_u);
            return 0;
        } else
            printf("Producto no existente\n");
        pp[d].bool == 1;
        return 0;
    }
    if (op_baja == 2) {
        busqueda_nombre();
        if (found == 1) {
            printf("\nProducto %s %s %s %s eliminado \n", &pp[d].clave, &pp[d].nombre, &pp[d].medida, &pp[d].precio_u);
            return 0;
        } else printf("Producto no existente\n");
        return 0;
    }
    return 0;
}

int ordenador(void) {
    for ( f = 0; f <= pt; f++) {
        for ( a = 0; a <= pt; a++) {
            if ((strcmp(pp[a].nombre, pp[a + 1].nombre)) > 0) {
                strcpy(cache, pp[a].clave);
                strcpy(pp[a].clave, pp[a + 1].clave);
                strcpy(pp[a + 1].clave, cache);
                strcpy(cache, pp[a].nombre);
                strcpy(pp[a].nombre, pp[a + 1].nombre);
                strcpy(pp[a + 1].nombre, cache);
                strcpy(cache, pp[a].medida);
                strcpy(pp[a].medida, pp[a + 1].medida);
                strcpy(pp[a + 1].medida, cache);
                strcpy(cache, pp[a].precio_u);
                strcpy(pp[a].precio_u, pp[a + 1].precio_u);
                strcpy(pp[a + 1].precio_u, cache);
            }
        }
    }

}

struct cotizar {
    char clave[10];
    char nombre[20];
    char medida[10];
    float cantidad;
    char p_unitario[5];
    float cantidad_total;
    float subtotal;
} cotizacion[20];

int cotizar(void) {
    while (continuar != 0) {
        busqueda_clave();
        if (found == 1) printf("\nProducto %s %s %s %s AGREGADOo \n", &pp[d].clave, &pp[d].nombre, &pp[d].medida, &pp[d].precio_u);
        else {
            printf("Final de cotizacion");
            continuar = 0;
        }
        if (found == 0) {
            printf("Clave inexistente, saliendo");
            return 0;
        }
        cot++;
        strcpy(cotizacion[cot].clave, pp[d].clave);
        strcpy(cotizacion[cot].nombre, pp[d].nombre);
        strcpy(cotizacion[cot].medida, pp[d].medida);
        strcpy(cotizacion[cot].p_unitario, pp[d].precio_u);
        printf("Ingresa la cantidad deseada de %s %s %s %s \n", &pp[d].clave, &pp[d].nombre, &pp[d].medida, &pp[d].precio_u);
        scanf("%s", &cotizacion[cot].cantidad);
        cant = cotizacion[cot].cantidad;
        subt = valoru*cant;
        cotizacion[cot].subtotal = subt;
        printf("Si deseas salir ingresa 0+enter, de lo contrario, ingresa cualquier tecla+enter");
        scanf("%d", &continuar);
    }


}

int mostrador_cot(void) {
    printf("  CLAVE   ");
    printf("  PRODUCTO      ");
    printf("MEDIDA");
    printf("CANT.");
    printf("PRECIO U.");
    for (i = 0; i <= cot; i++) {

        printf("%s ", &cotizacion[i].clave);
        printf("%s ", &cotizacion[i].nombre);
        printf("%s ", &cotizacion[i].medida);
        printf("%s ", &cotizacion[i].cantidad);
        printf("%s ", &cotizacion[i].cantidad_total);
        printf("%s\n", cotizacion[i].p_unitario);



    }
}

int opciones(void) {
    printf("Bienvenido a el sistema de control de\n RYAPS Miscelanea\n");
    printf("Elige la opcion que deses ejecutar\n");
    printf("Dar de baja algun producto....................[1]\n");
    printf("Dar de alta algun producto....................[2]\n");
    printf("Buscar un producto por clave..................[3]\n");
    printf("Buscar un producto por por nombre.............[4]\n");
    printf("Mostrar productos ordenados alfabeticamente...[5]\n");
    printf("Realizar una cotizacion.......................[6]\n");
    printf("Mostrar inventario............................[7]\n");
    printf("salir.........................................[0]\n");
}

int main() {
    bd = fopen("productos.txt", "r+");
    if (bd == NULL) {
        printf("El archivo no ha sido cargado con exito\nCerrando applicaion");
    } else printf("Bienvenido");
    rellenador();
    do {
        opciones();
        scanf(" %d", &resp_menu);
        while (resp_menu < 0 || resp_menu > 7) {
            opciones();
            scanf(" %d", &resp_menu);
        }
        switch (resp_menu) {
            case 1:
                system("clear");
                baja();
                printf("Para concluir presiona cualquer tecla + enter");
                getchar();
                break;
            case 2:
                system("clear");
                edit();
                mostrador();
                break;
            case 3:
                system("clear");
                busqueda_clave();
                break;
            case 4:
                system("clear");
                busqueda_nombre();
                break;
            case 5:
                system("clear");
                ordenador();
                mostrador();
                break;
            case 6:
                system("clear");
                cotizar();
                mostrador_cot();
                break;
            case 7:
                mostrador();
                break;
            case 0:
                break;
            default:
                printf("ERROR");
                break;
        }

    } while (resp_menu != 0);
    fclose(bd);
    return 0;
}
