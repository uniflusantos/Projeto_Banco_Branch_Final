#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  struct contas t[1000];
  int cont = 0;
  int posicao = 0;

  while (1) {
    printf("Menu de opcoes\n\n");
    printf("1 - Criar conta\n");
    printf("2 - Deletar conta\n");
    printf("3 - Listar Clientes\n");
    printf("4 - Realizar debito\n");
    printf("5 - Realizar deposito\n");
    printf("6 - Mostrar extrato\n");
    printf("7 - Realizar transferencia\n");
    printf("8 - Sair\n\n");
    printf("Digite o numero da opcao que deseja usar: ");

    char *p, s_opcao[100];
    int opcao;
    fgets(s_opcao, 100, stdin);
    opcao = strtol(s_opcao, &p, 10);

    if (opcao == 1) {
            //printf("\nVoce entrou na funcao de criar contas.\n\n");

            le_informacoes(t, cont);
            //buscar_cpf(t[cont].cpf,t,cont);
            cont++;

            printf("Conta cadastrada com sucesso!\n");
        }
  }
}
