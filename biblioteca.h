//
// Created by uniflusantos on 17/10/2023.
//

#ifndef UNTITLED19_BIBLIOTECA_H
#define UNTITLED19_BIBLIOTECA_H

typedef struct extrato {
    long cpf_origem;
    long cpf_destino;
    double entrada;
    double saida;
    double juros;
    int tipo;


}extrato;

struct contas{
    char nome[100];
    long cpf;
    int tipo_conta;
    int valor_inicial;
    char senha[100];
};

int buscar_cpf(long cpf, struct contas*t, int cont);


void limpa_buffer();

void le_informacoes(struct contas *armazena, int cont);

int deletar(int cont, struct contas *t);

void listar_contas(int cont, struct contas *t);

void debitar(int cont, struct contas *t);

void deposito(int cont, struct contas *t);

int transferencia(int cont, struct contas *t);

void extrato_funcao(int cont, struct contas *t);

int le_binario(struct contas *t, int *cont);

void escreve_binario(struct contas *t, int cont);


#endif //UNTITLED19_BIBLIOTECA_H
