#include <stdio.h>
#include <stdbool.h> //biblioteca para usar tipo bool (true e false)

int v[100];                     //Variavel global (tamanho do estacionamento).
unsigned int estacionados = 0;  //Variavel global (quantidade de estacionados, unsigned segura apenas valores positivos).

int estaNoEstacionamento(int carro)     //Checa se há carro no vetor.
{
    for (int i = 0; i < 100; i++)
    {
        if (v[i] == carro) //Caso o carro tal do funcionario tal esteja entrando pela primeira vez, ele percorre o vetor (estac) e confirma a vaga pro carro.
        {
            return true;
        }
    }
    return false;   //Caso já tenha um carro na respectiva vaga, ele retorna nada.
}

void addEstacionamento(int carro)   //Função de entrada do carro no estacionamento.
{

    if (estaNoEstacionamento) //Caso um funcionario tente estacionar 2x (entrar no estacionamento de novo).
    {
        printf("%d ja estava no estacionamento.\n", carro);
        vagasLivres();
        return;
    }

    if (estacionados == 100) //Caso estacionamento lotado
    {
        printf("Estacionamento cheio. Nao ha vagas\n\n");
        vagasLivres();
        return;
    }

    v[estacionados] = carro; //Caso entre pela primeira vez
    estacionados++;
    printf("%d entrou no estacionamento na vaga: %d\n", carro, estacionados);
    vagasLivres(estacionados);  //O carro que entrou vira um "estacionado".

}

void sairEstacionamento(int carro)  //Função de saida do carro no estacionamento.
{
    for (int i = 0; i < 100; i++)   //Percorre o vetor para verificar se o carro estava la mesmo.
    {
        if (v[i] == carro)  //Achou o que estava e agora quer sair.
        {
            v[i] = 0;
            estacionados--;
            printf("%d que estava na vaga %d saiu do estacionamento\n", carro, i + 1);
            vagasLivres();
            return;
        }

    }
    printf("%d nao estava no estacionamento.\n", carro);    //Caso um carro que nunca tenha entrado tente sair.
    vagasLivres();

}

void vagasLivres() //Falar quantas vagas sobram a cada operação.
{
    printf("Quantidade de vagas livres: %d\n\n", 100 - estacionados);
}


int main()  //Operaçoes de entrada e saida de veiculos.
{
    addEstacionamento(3);
    addEstacionamento(72);
    addEstacionamento(55);
    addEstacionamento(99);
    addEstacionamento(1);
    addEstacionamento(26);

    sairEstacionamento(72);
    sairEstacionamento(80);

    return 0;
}