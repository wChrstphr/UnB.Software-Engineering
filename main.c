#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "222037620.h"

int main() {
    int opcao;
    
    
    do {
        limpar_tela();
        menu();
    
        scanf("%d", &opcao);
        limpar_tela();
        switch (opcao) {
            case CADASTRAR_PESSOA:
            cadastrar_pessoa();
            break;
            case CONSULTAR_PESSOA:
            consultar_pessoa();
            break;
            case LISTAR_PESSOAS_CIDADE:
            printf("Not working\n");
            hub();
            break;
            case GERAR_RELATORIO:
            printf("Not working\n");
            hub();
            break;
            case EXCLUIR_PESSOA:
            printf("Not working\n");
            hub();
            break;
        }
    } while (opcao != 6);
    pause();
}