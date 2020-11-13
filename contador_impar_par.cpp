#include<stdio.h>
#include<stdlib.h>
int r=1;
int par=0;
int impar=0;
int main (){
printf("Ingresa los número que quieras comparar \nCuando quieras detenrte ingresa un '0' \n");
while(r!=0){
	scanf("%d",&r);
	if(r%2==0)par++;
	else impar++;
}
printf("\n %d Fue el numero de pares \n %d Fue el número de impares",par,impar);
return 0;
system ("pause");
}
