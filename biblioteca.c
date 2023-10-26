//
// Created by uniflusantos on 17/10/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "biblioteca.h"

void limpa_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int buscar_cpf(long cpf, struct contas*t, int cont){
    int saida = -1;
    for(int i = 0; i < cont; i++){
        if(t[i].cpf == cpf){
            saida = i;
        }
        //printf("indice :%d \n", i); (debug)
        //printf("cpf1: %ld \n", t[i].cpf); (debug)
        //printf("cpf2: %ld \n", cpf);(debug)
        //printf("saida %d \n", saida); (debug)
    }
    return saida;
}

void le_informacoes(struct contas *armazena, int cont){
    long cpf_recebido;
    int teste;
    int teste_conta;
        do{
            printf("Digite seu CPF: \n");
            scanf("%ld", &cpf_recebido);
            teste = buscar_cpf(cpf_recebido, armazena,cont);
            if(teste > -1){
                printf("CPF invalido, tente novamente.\n");
            }
        }while(teste > -1);
    
    armazena[cont].cpf = cpf_recebido;

    limpa_buffer();

    printf("Digite seu nome: \n");
    scanf("%[^\n]", armazena[cont].nome);
    limpa_buffer();

    do{
        printf("Digite o tipo de conta que deseja criar(1 para conta comum e 2 para conta plus): \n");
        scanf("%d", &teste_conta);

        if(teste_conta != 1 && teste_conta != 2){
            printf("Tipo de conta invalido. Entre com 1 para conta comum ou 2 para conta plus.\n");
        }
    } while(teste_conta < 1 || teste_conta > 2);
    armazena[cont].tipo_conta = teste_conta;
    limpa_buffer();

    printf("Digite o saldo inicial da conta: \n");
    scanf("%lf", &armazena[cont].valor_inicial);
    limpa_buffer();

    printf("Digite a senha: \n");
    scanf(" %[^\n]", armazena[cont].senha);
    limpa_buffer();
    armazena[cont].operacoes = 0;

}


int deletar(int cont, struct contas *t) {
    //printf("Entre com o CPF que vpcê deseja deletar: "); (debug)
    //scanf("%ld", &cpf); (debug)
    //buscar_cpf(cpf_recebido, armazena,cont); (debug)

    long cpf;

    if(cont ==0){
        printf("Nao existem contas cadastradas ainda.\n");
        return 1;
    }
    else {
        int teste;
        printf("Entre com o CPF que voce deseja deletar:  \n");
        scanf("%ld", &cpf);
        teste = buscar_cpf(cpf, t, cont);
        //printf("posicao delete: %d\n",teste); (debug)
        if (teste == -1) {
            printf("CPF inexistente, tente novamente.\n");
            limpa_buffer();
            return 1;
        }

        for (int i = teste; i < cont; i++) {
            t[i] = t[i + 1];
        }
        printf("Conta deletada !\n");
        limpa_buffer();
        return 0;
    }
}

void listar_contas(int cont, struct contas *t){
    if(cont ==0){
        printf("Nao existem contas cadastradas ainda.\n");
    }
    else {
        printf("Lista de Contas: \n\n");
        for (int x = 0; x < cont; x++) {
            printf("Conta %d\n", x + 1);
            printf("Nome: %s\n", t[x].nome);
            printf("CPF: %ld\n", t[x].cpf);
            if (t[x].tipo_conta == 1) {
                printf("Tipo de conta: Comum\n");
            } else if (t[x].tipo_conta == 2) {
                printf("Tipo de conta: Plus\n");
            }
            printf("Valor inicial: %.2lf\n", t[x].valor_inicial);
            printf("Senha: %s\n\n", t[x].senha);
        }
    }
}


