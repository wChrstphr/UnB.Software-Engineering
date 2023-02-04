#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "222037620.h"

int main() {
    int opcao;
    int numero;
    
    do {
        limpar_tela();
        menu();
        numero = scanf("%d", &opcao);
        if (numero == 1) {
            limpar_tela();
            switch (opcao) {
                case CADASTRAR_PESSOA:
                cadastrar_pessoa();
                break;
                case CONSULTAR_PESSOA:
                consultar_pessoa();
                break;
                case LISTAR_PESSOAS_CIDADE:
                listar_pessoas_cidade();
                break;
                case GERAR_RELATORIO:
                gerar_relatorio();
                hub();
                break;
                case EXCLUIR_PESSOA:
                excluir_pessoa();
                break;
            }
        } else {
            limpar_tela();
            printf("Input invalido.");
            break;
        }
    } while (opcao != 6);
    pause();
}