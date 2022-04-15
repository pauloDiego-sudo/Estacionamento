#include <stdio.h>

/*Para a entrada
  1. Coletar a placa
  2. Escolher vaga
  3. Verificar se a vaga tá livre ou ocupada
  4. Ao estacionar trocar o numero 0 pela placa

quando um valor for 1 significa existe/ocupado quando for 0 ñexiste/livre*/

int vaga[5][20]; //estacionamento
int olharvaga(int i, int j, int p);
int olharcarro(int p);
void saida(int p);

int main() {
  int p, v, i, j, option; //p-placa, v-vaga, i ej - da matriz

  for(i=0; i<5; i++){
  for(j=0; j<20; j++){
    vaga[i][j]=0;}  } // vaga do estacionamento = 0
  
  do{
  printf("2.Entrada 3.Saída 4.Estacionamento 7.Finalizar\n");
  scanf("%i", &option);
  
  if(option==2) {
        printf("Número da placa: ");  scanf("%i", &p);
        if      (olharcarro(p)==1){printf("Este carro já está no estacionamento\n");}
        else if (olharcarro(p)==0){
            printf("Andar: ");        scanf("%i", &i);
            printf("Vaga: ");         scanf("%i", &j);
            if      (olharvaga(i, j, p)==0){printf("Carro Estacionado.\n");}
            else if (olharvaga(i, j, p)==1){printf("Vaga ocupada.\n");}  }  }

    if(option==3){
        printf("Número da placa: ");  scanf("%i", &p);
        if      (olharcarro(p)==0){printf("Este carro não está no estacionamento\n");}
        else if (olharcarro(p)==1){printf("Carro saiu, vaga liberada.\n"); saida(p);}  }
    
    if(option==4){
      for(int i=0; i<5; i++){
      for(int j=0; j<20; j++){printf(" %i ",vaga[i][j]);}printf("\n");}  }

    if(option==7){
      printf("Sistema Finalizado");}
    
    }  while(option!=7); 
  return 0;  }



int olharcarro(int p){
  int repost=0;
    for(int i=0; i<5; i++){ //vê se o carro já existe no estacionamento.
    for(int j=0; j<20; j++){
        if(vaga[i][j]==p){repost=1;}  }  } 
  return repost; }


int olharvaga(int i, int j, int p){ int valor=0;
    if (vaga[i][j-1]==0){vaga[i][j-1]=p;} //verifica e estaciona
    else if (vaga[i][j-1]!=0){valor=1;}
  return valor;  }


void saida(int p){
  for(int i=0; i<5; i++){ //encontra o carro e retira ele
  for(int j=0; j<20; j++){
      if(p==vaga[i][j]){vaga[i][j]=0;}  }  }  }
