#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int estacionados;
int e[10][10];
int c[10][2];

void vagasLivres(){
    printf("Quantidade de vagas livres: %d\n\n", 100 - estacionados);
}

int fazerCadastro(int nome, int placa){
    int i, j;
    for(i = 0; i < 10; i++){
        for (j = 0; j < 2; j++) {
            if (c[i][j] == 0) {
                c[i][j] = nome;
                c[i][j + 1] = placa;
                break;
            }
        }
        if (c[i + 1][0] == 0) {
            c[i][j] = nome;
            c[i][j + 1] = placa;
            break;
        }
    }
    verCadastro();
}

int verCadastro(){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", c[i][j]);
        }
    printf("\n");
    }
}



int estaEstacionado(int placa){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++) {
            if(e[i][j] == placa) {
                printf("O carro da placa %d esta no estacionamento\n\n", placa);
                return true;
            }
        }
    }
    printf("O carro da placa %d nao esta no estacionamento\n\n", placa);
    return false;
}

bool estacionamentoCheio() {
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(e[i][j] != 0){
                printf("Estacionamento cheio. Nao ha vagas.\n");
                vagasLivres();
                return true;
            }
        }
    }
    return false;
}

bool estaCadastrado(int placa) {
    int i, j;
    for(i = 0; i < 10; i++){
        if (c[i][1] == placa) {
            return true;
        }
    }
    return false;
}

void addEstacionamento(int placa){
    int i, j;
    if (!estaCadastrado(placa)) {
        printf("A placa %d nao esta cadastrada\n\n", placa);
        return;
    }
    if (estaEstacionado(placa)) {
        printf("O carro de placa %d ja esta no estacionamento.\n\n", placa);
        vagasLivres();
        return;
    }

    for(i = 0; i < 10; i++) {
        
        for(j = 0; j < 10; j++) {
            if (e[i][j] == 0) {
                e[i][j] = placa;
                estacionados++;
                printf("O carro de placa %d entrou no estacionamento na vaga: %d\n", placa, estacionados);
                vagasLivres(estacionados);
                return;
            }
        }
        if (e[i][j + 1] == 0) {
            e[i][j] = placa;
            estacionados++;
            printf("O carro de placa %d entrou no estacionamento na vaga: %d\n", placa, estacionados);
            vagasLivres(estacionados);
            break;
        }
    }
}

void sairEstacionamento(int placa) {
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(e[i][j] == placa){
                e[i][j] = 0;
                estacionados--;
                printf("O carro da placa %d que estava na vaga %d saiu do estacionamento\n", placa, i + 1);
                vagasLivres();
                return;
            }
        }

    }
    printf("O carro da placa %d nao estava no estacionamento.\n", placa);
    vagasLivres();
}





int main(){

int escolha, nome, placa;

    while(true){
        printf("APERTE 1 PARA CADASTRAR UM NOVO SERVIDOR.\n");
        printf("APERTE 2 PARA AUTORIZAR A ENTRADA NO ESTACIONAMENTO.\n");
        printf("APERTE 3 PARA AUTORIZAR A SAIDA NO ESTACIONAMENTO.\n");
        printf("APERTE 4 PARA VERIFICAR AS VAGAS RESTANTES.\n");
        printf("APERTE 5 PARA VER A LISTA DE CADASTRADOS.\n");
        printf("APERTE 6 PARA VERIFICAR QUEM ESTA NO ESTACIONAMENTO.\n");
        printf("APERTE 7 PARA FINALIZAR O PROGRAMA.\n");

        scanf("%d", &escolha);
        
    switch (escolha){
        case 1:
            printf("Digite o nome do servidor:\n");
            scanf("%d", &nome);
            printf("Digite a placa do veiculo:\n");
            scanf("%d", &placa);
            fazerCadastro(nome, placa);
            break;
        case 2:
            printf("Digite a placa do veiculo:\n");
            scanf("%d", &placa);
            addEstacionamento(placa);
            break;
        case 3:
            printf("Digite a placa do veiculo:\n");
            scanf("%d", &placa);
            sairEstacionamento(placa);
            break;
        case 4:
            vagasLivres();
            break;
        case 5:
            verCadastro();
            break;
        case 6:
            printf("Digite a placa do veiculo:\n");
            scanf("%d", &placa);
            estaEstacionado(placa);
            break;
        case 7:
            printf("O PROGRAMA FOI FINALIZADO.\n");
            return 0;
        default:
            break;
    }   

    }
    return 0;
}