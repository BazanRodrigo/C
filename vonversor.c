#include<stdio.h>
#include<stdlib.h>
int r;
float m,pul,mili,yar,m,mi,km;
int main (){
	printf("Selecciona la convercion que deseas \n");
	printf("De pulgada a milimetros...........(1) \n");
	printf("De Yarda a metros.................(2)\n");
	printf("De milla a kilomerros.............(3)\n");
	scanf("%d",&r);
	while(r<1 || r>3){
		printf("Ingresa una opcion valida\n");
		scanf("%d",&r);
		}
		switch (r){
			case 1: 
			printf("Ingresa la cantidad de pulgadas \n");
			scanf("%f",&pul);
			mili=(pul*25.4);
			printf("Tus %.2f pulgadas equivalen a %.3f milimetros ",pul,mili);
			break;
			case 2: 
			printf("Ingresa la cantidad de yardas \n");
			scanf("%f",&yar);
			m=(yar*0.9144);
			printf("Tus %.2f yardas equivalen a %.3f metros ",yar,m);
			break;
			case 3: 
			printf("Ingresa la cantidad de millas \n");
			scanf("%f",&mi);
			km=(mi*1.6093);
			printf("Tus %.2f millas equivalen a %.3f kilomilimetros ",mi,km);
			break;
			}
return 0;
system("pause");
}
