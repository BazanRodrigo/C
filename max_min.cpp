#include<stdio.h>
#include<stdlib.h>
int r=1;
int max=0;
int min=0;
int main (){
printf("Ingresa los número que quieras comparar \nCuando quieras detenrte ingresa un '0' \n");
while(r!=0){
	scanf("%d",&r);
	if(r<min)min=r;
	if(r>max)max=r;
}
printf("\n %d Fue el numero maximo \n %d Fue el número minimo",max,min);
return 0;
system ("pause");
}
