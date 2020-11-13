#include<stdio.h>
#include<stdlib.h>
char nombre,clave;
int r,registro [100][3];
int main(){
printf("Selecciona que deseas hacer \n");
printf("Ingresar producto............(1)\n");
printf("Informacion de un producto...(2)\n");
scanf("%d",&r);
while(r!=1 || r!=2){
	printf("Ingresa una opcion valida \n");
	}
	switch(r){
	case 1:
	for (int i=1;i>100;i++){
		printf("Ingresa el nombre del producto \n");
		scanf("%c",&nombre);
		}
	break;
	case 2:
	break;
	}
system("pause");
return 0;
}
