#include <stdio.h>

int main() {
  char c[100];
  int estado, numero[100], j,i,k,n, fat, casa, casa2, aux2, aux, nelementos;
  float soma, numero2[100];
  soma=0, j=0, i=0, k=0, estado =0;
  casa=1.0, casa2=1.0;
  for(k=0; k<100; k++){
    numero[k]=0;
    numero2[k]=0;
  }

  gets(c);
for (j=0, nelementos=0; c[j]!='\0'; j++){
        nelementos++;
}
for (j=0; j<=nelementos; j++){
    aux=c[j]-48;
  switch (estado)
{
  case 0:
    casa=0, casa2=0;
      for(k=0; k<100; k++){
    numero[k]=0;
    numero2[k]=0;
  }
    if (aux==-2){
      estado=3;
      }
    else if (aux<=-16){
      estado=1;
      }
    else if (aux>=0 && aux<=9 && j==0){
      j--;
      estado=1;
    }
    else estado=0;
  break;
  case 1:
    if (aux<=-16){
        j--;
      estado=2;
      }
    else if (aux>=0 && aux<=9){
       numero[casa] = aux;
      casa++;
      estado=1;
      }
    else if (aux==-2){

      estado=3;
      }
    else if (aux==-15){
      n=c[j-1]-48;
      numero[casa-1]-=n;
      estado=5;
      }
    else estado=0;
  break;
  case 2:
       for(k=casa-1, aux2=1; k>=0; k--){
        soma=soma + numero[k]*aux2;
        aux2=aux2*10;
  }
    j--;
    estado=0;
  break;
  case 3:
    if (aux<=-16){
        j--;
      estado=4;
      }
    else if (aux>=0 && aux<=9){
       numero2[casa2] = aux;
      casa2++;
      estado=3;
      }
    else estado=0;
   break;
   case 4:
        for(k=casa-1, aux2=1; k>=0; k--){
        soma=soma + numero[k]*aux2;
        aux2=aux2*10;
  }
       for(k=0, aux2=10; k<casa2; k++){
        soma=soma + numero2[k]/aux2;
        aux2=aux2*10;
  }
     j--;
    estado=0;
  break;
   case 5:
      if (aux<=-16){
        for(fat=1; n>1; n--) {
                fat = fat * n;
        }
        j--;
        estado=6;
      }
    else estado=0;
  break;
     case 6:
        for(k=casa-1, aux2=1; k>=0; k--){
        soma=soma + numero[k]*aux2;
        aux2=aux2*10;
  }
        soma+=fat;
       for(k=0, aux2=10; k<casa2; k++){
        soma=soma + numero2[k]/aux2;
        aux2=aux2*10;
  }
     j--;
    estado=0;
  break;
  }
}
  printf("%.2f\n", soma);
  return 0;
}
