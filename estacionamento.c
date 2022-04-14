#include <stdio.h>

/*Para a entrada
  1. Coletar a placa
  2. Escolher vaga
  3. Verificar se a vaga tá livre ou ocupada
  4. Ao estacionar trocar o numero 0 pela placa

quando um valor for 1 significa existe/ocupado quando for 0 ñexiste/livre*/

int vaga[10][10]; //estacionamento
int pv[10][10]; //um pseudo estacionamento para pegar o lugar
int olharvaga(int v, int p);
int olharcarro(int p);
void saida(int p);

int main() {
  int p, v, l=1, option; //p-placa, v-vaga, l-para preencher

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      pv[i][j]=l; vaga[i][j]=0;
      l++; }  } //preencher pseudovagas de 1 a 100 e vaga do estacionamento = 0
  
  do{
  printf("2.Entrada 3.Saída 4.Estacionamento 5.Finalizar\n");
  scanf("%i", &option);
      
    if(option==2){
        printf("Número da placa: ");  scanf("%i", &p);
        if      (olharcarro(p)==1){printf("Este carro já está no estacionamento\n");}
        else if (olharcarro(p)==0){
            printf("Vaga: ");             scanf("%i", &v);
            if      (olharvaga(v, p)==0){printf("Carro Estacionado.\n");}
            else if (olharvaga(v, p)==1){printf("Vaga ocupada.\n");}    }   }

    if(option==3){
        printf("Número da placa: ");  scanf("%i", &p);
        if      (olharcarro(p)==0){printf("Este carro não está no estacionamento\n");   }
        else if (olharcarro(p)==1){printf("Carro saiu, vaga liberada.\n"); saida(p);    }   }
    
    if(option==4){
      for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){printf(" %i ",vaga[i][j]);}printf("\n");}  }
      
    if(option==5){printf("Sistema Finalizado");}
    
  } while (option!=5);
  
  return 0;  }



int olharcarro(int p){
  int repost=0;
    for(int i=0; i<10; i++){ //vê se o carro já existe no estacionamento.
    for(int j=0; j<10; j++){
        if(p==vaga[i][j]){repost=1;}  }  } return repost; }


int olharvaga(int v, int p){
  int i, j, valor;
      for(int i=0; i<10; i++){ //ao achar a vaga, ele vê se ta livre ou ocupada.
      for(int j=0; j<10; j++){ // se tiver livre ele já estaciona o carro
          if(v==pv[i][j]){
            if      (vaga[i][j]==0){valor=0; vaga[i][j]=p;} 
            else if (vaga[i][j]!=0){valor=1;}
          break;}  }  }
  return valor;  }


void saida(int p){
  for(int i=0; i<10; i++){ //encontra o carro e retira ele
  for(int j=0; j<10; j++){
      if(p==vaga[i][j]){vaga[i][j]=0;}  }  }  }
