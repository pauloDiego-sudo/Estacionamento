#include <stdio.h>

int n=5,srvCarro[5][2],vaga[5][20]; //n servidores, matriz servidor - carro, matriz do estacionamento

void preencheM(void){
  int i,j;
  for(i=0;i<n;i++){ // preenche a matriz srvCarro com 0 
    for(j=0;j<2;j++){
      srvCarro[i][j]=0;
    }
  }
  for(i=0;i<5;i++){ // preenche a matriz estacionamento com 0 
    for(j=0;j<20;j++){
      vaga[i][j]=0;
    }
  }
  return;
}
int verificaCad(int matricula){
  int ans=0,i;
  for(i=0;i<n;i++){ //ele só verifica o servidor na matriz (primeira coluna)
    if(srvCarro[i][0]==0){
      continue;
    }
    else if(matricula==srvCarro[i][0]){
      ans=1;    
    }
    else{
      continue;
      }
    } 
  return ans;
}
int verificaCarro(int placa){
  int ans=0,i;
  for(i=0;i<n;i++){ //ele só verifica o servidor na matriz (primeira coluna)
    if(srvCarro[i][1]==0){
      continue;
    }
    else if(placa==srvCarro[i][1]){
      ans=1;    
    }
    else{
      continue;
      }
    } 
  return ans;
}
void cadastro(void){
  int i,j,matricula,placa,checkid;
  printf("Matricula: "); 
  scanf("%d",&matricula);
  if(matricula>0){
    checkid = verificaCad(matricula); 
    if(checkid==1){ //verifica se o cara tá cadastrado
      printf("Já cadastrado!\n");
    }
    else if(checkid==0){ //se não, ele cadastra o cara
      for(i=0;i<n;i++){
        if(srvCarro[i][0]!=0){ //se o valor da matriz for diferente de 0, ele n faz nada
          continue;
        }
        else{ 
          srvCarro[i][0]=matricula; //só é necessário analisar a matriz unidimensionalmente, pois, se não tiver servidor cadastrado na primeira coluna, não terá carro cadastrado na segunda, e se tiver, ele é ignorado
          printf("Placa do Carro: ");
          scanf("%d",&placa);
          srvCarro[i][1]=placa;
          break;
          }
        }
      }
  }
  else{
    printf("Matricula inválida!\n");
  }
  return;
}
void imprimeM(void){
  int i,j;
  for(i=0;i<n;i++){ // imprime a matriz 
    printf("[");
    for(j=0;j<2;j++){
      printf(" %2d ",srvCarro[i][j]);
    }
    printf("] \n");
  }
}
void imprimeMEstac(void){
  int i,j;
  for(i=0;i<5;i++){ // imprime a matriz 
    printf("[");
    for(j=0;j<20;j++){
      printf(" %2d ",vaga[i][j]);
    }
    printf("] \n");
  }
}

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




int main(void) {
  int opc=1,m,p,v,i,j;
  preencheM();
  while(opc!=0){
  printf("Escolha uma opção: \n 1-Cadastrar \n 2- Verificar cadastro \n 3-Imprime matriz de servidores \n 4-Entrada \n 5-Saida \n 6-Estacionamento \n 0-End \n ");
  scanf("%d",&opc);
  switch(opc){
    case 1:
      cadastro();
      break;
    case 2:
      printf("Digite a matricula: ");
      scanf("%d",&m);
      if(verificaCad(m)==1){
        printf("Servidor ja cadastrado! \n ");
      }
      else{
        printf("Servidor não cadastrado! \n ");
      }
      break;
    case 3:
      imprimeM();
      break;
    case 4:
      printf("Número da placa: ");  scanf("%i", &p);
      if(verificaCarro(p)==1){
        if(olharcarro(p)==1){printf("Este carro já está no estacionamento\n");}
        else if (olharcarro(p)==0){
        printf("Andar: ");scanf("%i", &i);
        printf("Vaga: ");scanf("%i", &j);
        if(olharvaga(i, j, p)==0){printf("Carro Estacionado.\n");}
        else if (olharvaga(i, j, p)==1){printf("Vaga ocupada.\n");}  }
      }
      else if(verificaCarro(p)==0){
        printf("Carro nao cadastrado! \n");
      }
      break;
    case 5:
      printf("Número da placa: ");  scanf("%i", &p);
      if(olharcarro(p)==0){printf("Este carro não está no estacionamento\n");}
      else if(olharcarro(p)==1){printf("Carro saiu, vaga liberada.\n"); saida(p);}
      break;
    case 6:
      imprimeMEstac();
      break;
    case 0:
      break;
    default:
      printf("Escolha uma opção VÁLIDA\n");
      break;
    }
  }
  return 0;
}
