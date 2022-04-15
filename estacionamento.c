#include <stdio.h>
int n=5,srvCarro[5][2]; //n servidores, matriz servidor - carro
void preencheM(void){
  int i,j;
  for(i=0;i<n;i++){ // preenche a matriz srvCarro com 0 
    for(j=0;j<2;j++){
      srvCarro[i][j]=0;
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
int main(void) {
  int opc=1,m;
  preencheM();
  while(opc!=0){
  printf("Escolha uma opção: \n 1-Cadastrar \n 2- Verificar \n 3-Imprime matriz de servidores \n 0-End \n ");
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
    case 0:
      break;
    default:
      printf("Escolha uma opção VÁLIDA\n");
      break;
    }
  }
  return 0;
}
