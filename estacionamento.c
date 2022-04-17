#include <stdio.h>
#include <stdbool.h>

int n=5,a=5,vags=20,srvCarro[5][2],vaga[5][20],vagasLivres=100,estacionados=0; //n servidores, a andares, vags vagas, matriz servidor-carro, matriz do estacionamento

void preencheM(void){
  int i,j;
  for(i=0;i<n;i++){ // preenche a matriz srvCarro com 0 
    for(j=0;j<2;j++){
      srvCarro[i][j]=0;
    }
  }
  for(i=0;i<a;i++){ // preenche a matriz estacionamento com 0 
    for(j=0;j<vags;j++){
      vaga[i][j]=0;
    }
  }
  return;
}
int verificaCadECarro(int matricula){
  int ans=0,i;
  for(i=0;i<n;i++){ //ele só verifica o servidor na matriz (primeira coluna) e retorna a placa de seu carro
    if(srvCarro[i][0]==0){
      continue;
    }
    else if(matricula==srvCarro[i][0]){
      ans=srvCarro[i][1];   
    }
    else{
      continue;
      }
    } 
  return ans;
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
  for(i=0;i<n;i++){ //ele só verifica o carro na segunda coluna
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
  int i,j,matricula,placa,checkid,checkcarro;
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
 //só é necessário analisar a matriz unidimensionalmente, pois, se não tiver servidor cadastrado na primeira coluna, não terá carro cadastrado na segunda, e se tiver, ele é ignorado
          printf("Placa do Carro: ");
          scanf("%d",&placa);
          if(placa>0){
            checkcarro=verificaCarro(placa);
            if(checkcarro==1){ //verifica se o carro tá cadastrado
            printf("Carro já cadastrado!\n");
            
            }
          else if(checkcarro==0){ //se nao, então ele cadastra o cara e o carro
              srvCarro[i][0]=matricula; 
              srvCarro[i][1]=placa;
              printf("Servidor e carro cadastrado!\n");
          }
          break;
          }
          else{printf("Placa inválida!\n");break;}
          }
        }
      }
  }
  else{
    printf("Matricula inválida!\n"); //valores <=0 não são aceitos
  }
  return;
}
void imprimeM(void){
  int i,j;
  for(i=0;i<n;i++){ // imprime a matriz de servidor e carro
    printf("[");
    for(j=0;j<2;j++){
      printf(" %2d ",srvCarro[i][j]);
    }
    printf("] \n");
  }
}
void imprimeMEstac(void){
  int i,j;
  for(i=0;i<a;i++){ // imprime a matriz do estacionamento
    printf("[");
    for(j=0;j<vags;j++){
      printf(" %2d ",vaga[i][j]);
    }
    printf("] \n");
  }
}

int olharcarro(int p){
  int repost=0;
    for(int i=0; i<a; i++){ //vê se o carro já existe no estacionamento. e retorna sim ou nao (1 ou 0) serve para a função de entrada no estacionamento
    for(int j=0; j<vags; j++){
        if(vaga[i][j]==p){repost=1;}  }  } 
  return repost; 
  }

int estaEstacionado(int placa){ //Vê se o carro está no etacionamento, e retorna o local, com andar e vaga ocupada
    int i, j;
    for(i = 0; i < a; i++){
        for(j = 0; j < vags+1; j++) {
            if(vaga[i][j] == placa) {
                printf("O carro da placa %d esta no estacionamento\n Andar: %d Vaga: %d\n", placa,i,j+1);
                return true;
            }
        }
    }
    printf("O carro da placa %d nao esta no estacionamento\n\n", placa);
    return false;
}

int olharvaga(int i, int j, int p){ 
  int valor=0;
  if (vaga[i][j-1]==0){
    vaga[i][j-1]=p; //estaciona
    vagasLivres--; //menos vagas à cada estacionada
    estacionados++;
    } //verifica se a vaga está livre e estaciona
  else if(vaga[i][j-1]!=0){
    valor=1;
    }
  
  return valor;  
  }


void saida(int p){
  for(int i=0; i<a; i++){ //encontra o carro e retira ele e devolve a vaga pro contador
  for(int j=0; j<vags; j++){
      if(p==vaga[i][j]){vaga[i][j]=0;vagasLivres++;estacionados--;}  }  }  }


int main(void) {
  int opc=1,m,p,v,i,j;
  preencheM();
  while(opc!=0){
  printf("Escolha uma opção: \n 1-Cadastrar \n 2-Verificar cadastro \n 3-Verificar servidores e carros \n 4-Entrada \n 5-Saida \n 6-Ver Estacionamento \n 7-Vagas Livres e ocupadas \n 8-Ver carro no estacionamento \n 0-End \n ");
  scanf("%d",&opc);
  switch(opc){
    case 1:
      cadastro();
      break;
    case 2:
      printf("Digite a matricula: ");
      scanf("%d",&m);
      if(m<1){
        printf("Cadastro inválido! \n ");
      }
      else if(verificaCad(m)==1){
        printf("Servidor ja cadastrado! \n ");
        printf("Placa do veículo: %d \n ",verificaCadECarro(m));        
      }
      else{
        printf("Servidor não cadastrado! \n ");
      }
      break;
    case 3:
      imprimeM();
      break;
    case 4:
      if(vagasLivres>0){
        printf("Número da placa: ");  scanf("%i", &p);
        if(verificaCarro(p)==1){
          if(olharcarro(p)==1){printf("Este carro já está no estacionamento\n");}
          else if (olharcarro(p)==0){
          printf("Andar: ");scanf("%i", &i);
          if(i>-1 && i<a){
            printf("Vaga: ");scanf("%i", &j);
            if(j>-1 && j<vags+1){
              if(olharvaga(i, j, p)==0){printf("Carro Estacionado.\n");}
              else if (olharvaga(i, j, p)==1){printf("Vaga ocupada.\n");}
            }
            else{printf("Essa vaga não existe! Escolha entre %d e %d \n",vags/vags,vags);break;}
            }
          else{printf("Esse andar não existe! Escolha entre %d e %d \n OBS: 0 = Terreo\n",0,a-1);break;}
            }
        }
        else if(verificaCarro(p)==0){
          printf("Carro nao cadastrado! \n");
        }
      }
      else{printf("Não há vagas livres! \n");break;}
      break;
    case 5:
      printf("Número da placa: ");  scanf("%i", &p);
      if(p>0){
        if(olharcarro(p)==0){printf("Este carro não está no estacionamento\n");}
        else if(olharcarro(p)==1){printf("Carro saiu, vaga liberada.\n"); saida(p);}}
      else{printf("Placa inválida \n");}
      break;
    case 6:
      imprimeMEstac();
      break;
    case 7:
      printf("Vagas Livres: %d \n Vagas ocupadas: %d \n",vagasLivres,estacionados);
      break;
    case 8:
      printf("Digite a placa do veiculo:\n");
      scanf("%d", &p);
      estaEstacionado(p);
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
