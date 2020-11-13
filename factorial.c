#include<stdio.h>
#include<stdlib.h>
int n, nf=1;
int main (){
printf("Ingresa el número a calcular factorial \n");
scanf("%d",&n);
if(n<0)printf("No existe factorial de numeros negativos");
else{
for(int i=1;i<=n;++i)nf=nf*i;
printf("\n El factorial de %d es de %d \n",n,nf);
}
return 0;
system ("pause");
}

