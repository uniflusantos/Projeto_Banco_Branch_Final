//
// Created by uniflusantos on 17/10/2023.
//

#ifndef UNTITLED19_BIBLIOTECA_H
#define UNTITLED19_BIBLIOTECA_H

struct contas{
    char nome[100];
    long cpf;
    int tipo_conta;
    int valor_inicial;
    char senha[100];
};

int buscar_cpf(long cpf, struct contas*t, int cont);

void limpa_buffer();
#endif //UNTITLED19_BIBLIOTECA_H
