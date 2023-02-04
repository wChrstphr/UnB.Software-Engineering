#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <search.h>
#include <time.h>

#define TAM_MAX 101
#define TAM_MAX_LINHAS 101
#define TAM_CODIGO 7
#define TAM_CPF 15
#define TAM_NOME 101
#define TAM_CIDADE 35 /** Por conta do municipio "Vila Bela da Santissima Trindade" **/
#define TAM_UF 3
#define CADASTRAR_PESSOA 1
#define CONSULTAR_PESSOA 2
#define LISTAR_PESSOAS_CIDADE 3
#define GERAR_RELATORIO 4
#define EXCLUIR_PESSOA 5
#define ENCERRAR_PROGRAMA 6
int verificador_letras();
int verificador_data();
int verificar_cpf();
void hub();
char maiusculo();
int ano_atual();
int tem_cadastros();
void limpar_buffer();
void limpar_tela();
void capitalizar();

/**.................................. Declaracao de structs (estruturas heterogenea) ..................................**/
typedef struct pessoa {
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    char sexo;
    int dia;
    int mes;
    int ano;
    char cidade[TAM_CIDADE];
    char uf[TAM_UF];
} PESSOA;

typedef struct cidades {
    char codigo[TAM_CODIGO];
    char uf[TAM_UF];
    char cidade_com_acento[TAM_CIDADE];
    char cidade_sem_acento[TAM_CIDADE];
} CIDADES;

/**.................................. Declarando funcoes principais do codigo .........................................**/
void menu() {
    printf(".........Bem-vindo(a) ao Sistema de Gestao de Beneficio Social (SGBS).........\n\n");
    printf("Menu:\n");
    printf("1) Cadastrar Pessoa\n");
    printf("2) Consultar Pessoa\n");
    printf("3) Listar pessoas por Cidade\n");
    printf("4) Gerar relatorio\n");
    printf("5) Excluir Pessoa\n");
    printf("6) Encerrar Programa\n");
}

/**.................................. Funcao para cadastrar pessoa ....................................................**/
void cadastrar_pessoa() {
    /** Variaveis **/
    FILE *arquivo;  /** Aponta para o arquivo que sera aberto **/
    FILE *cidades;
    PESSOA reg;     /** Variavel do tipo struct pessoa para registrar **/
    PESSOA cmpr;    /** Variavel do tipo struct pessoa para comparar **/
    CIDADES cmprr;
    int existe_cpf;
    int sexo_valido;
    int cpf_novo[TAM_CPF], tot_d1 = 0, tot_d2 = 0, digito_calculado, digito_usuario, i, a = 0, tam;
    int cpf_valido;
    int nome_valido;
    int data_valida;
    int opcao_cadastro;
    int existe_cidade;
    int existe_uf;
    /** Verificando se ja existe um arquivo "cadastros.txt", caso nao exista, criaremos um **/
    arquivo = fopen("cadastros.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("cadastros.txt.", "a");
    }
    /**
     ********** Instrucoes e entrada de dados **********

     * Lendo o CPF
    **/
    limpar_buffer(); /** Para ler uma string sem que haja lixo no buffer de entrada de dados **/
    printf("Digite o CPF (000.000.000-00): ");
    scanf("%[^\n]", reg.cpf);

    /**
		Verificando validez do CPF e existencia dupla
        1) Verificando se o CPF eh valido e retornando 1 (valido) e 0 (invalido)
    **/
    cpf_valido = 0;
    int verificador = verificar_cpf(reg.cpf);
    if (verificador == 1) {
        cpf_valido = 1;
    }
    /** 2) Verificando para saber se ja ha um CPF igual ao digitado no meu arquivo "cadastros.txt" **/
    arquivo = fopen("cadastros.txt", "r"); /** Abrindo o arquivo **/
    existe_cpf = 0;

    while ( !feof(arquivo)) {
        fscanf(arquivo, "%[^\n]\n", cmpr.cpf);
        fscanf(arquivo, "%[^\n]\n", cmpr.nome);
        fscanf(arquivo, "%c\n\n", &cmpr.sexo);
        fscanf(arquivo, "%d\n\n", &cmpr.dia);
        fscanf(arquivo, "%d\n\n", &cmpr.mes);
        fscanf(arquivo, "%d\n\n", &cmpr.ano);
        fscanf(arquivo, "%[^\n]\n", cmpr.cidade);
        fscanf(arquivo, "%[^\n]\n", cmpr.uf);

        /** Checando se o CPF que li eh igual ao que digitado **/
        if (strcmp(reg.cpf, cmpr.cpf) == 0) {
            existe_cpf = 1;
        }
    } fclose(arquivo); /** Fechando o arquivo para nao dar problema de seguimento **/

	/** Lendo o nome **/
    limpar_buffer();
    printf("Digite o nome completo (Apenas letras): ");
    scanf("%[^\n]", reg.nome);
    capitalizar(reg.nome);
    /** Verificando se foram digitadas apenas letras para a varivel reg.nome **/
    nome_valido = 0;
    if (verificador_letras(reg.nome) == 1) {
       nome_valido = 1;
    }

	/** Lendo o sexo **/
    limpar_buffer();
    printf("Digite o sexo (M ou F): ");
    scanf("%c", &reg.sexo);
    reg.sexo = toupper(reg.sexo);
    sexo_valido = 0;
    if (reg.sexo == 'M' || reg.sexo == 'F') {
        sexo_valido = 1;
    }
    printf("Digite o dia de nascimento: ");
    scanf("%d", &reg.dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &reg.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &reg.ano);
    /** Verificando se a data digitada eh uma data valida **/
    data_valida = 0;
    if (verificador_data(reg.dia, reg.mes, reg.ano) == 1) {
        data_valida = 1;
    }

    /** Lendo a cidade **/
    printf("Digite a cidade: ");
    limpar_buffer();
    scanf("%[^\n]", reg.cidade);

    /** Verificando para saber se ja ha uma cidade igual a digitada no meu arquivo "uf_cidades.txt" **/
    cidades = fopen("uf_cidades.txt", "r");
    existe_cidade = 0;

    while ( !feof(cidades)) {
        fscanf(cidades, "%[^\n]\n", cmprr.codigo);
        fscanf(cidades, "%[^\n]\n", cmprr.uf);
        fscanf(cidades, "%[^\n]\n", cmprr.cidade_com_acento);
        fscanf(cidades, "%[^\n]\n", cmprr.cidade_sem_acento);
        capitalizar(reg.cidade);
        capitalizar(cmprr.cidade_sem_acento);
        /** Checando se a cidade que li eh igual ao que foi digitado **/
        if (strcmp(reg.cidade, cmprr.cidade_sem_acento) == 0) {
            existe_cidade = 1;
        }
    }
    fclose(cidades); /** Fechando o arquivo para nao dar problema de seguimento **/
    printf("Digite a UF: ");
    limpar_buffer();
    scanf("%[^\n]", reg.uf);
    /**  Verificando para saber se ja ha uma UF igual a digitada no meu arquivo "uf_cidades.txt" **/

    cidades = fopen("uf_cidades.txt", "r"); /** Abrindo o arquivo **/
    existe_uf = 0;

    while ( !feof(cidades)) {
        fscanf(cidades, "%[^\n]\n", cmprr.codigo);
        fscanf(cidades, "%[^\n]\n", cmprr.uf);
        fscanf(cidades, "%[^\n]\n", cmprr.cidade_com_acento);
        fscanf(cidades, "%[^\n]\n", cmprr.cidade_sem_acento);
        maiusculo(reg.uf);
        maiusculo(cmprr.uf);
        /** Checando se a UF que li eh igual ao que foi digitado **/
        if (strcmp(reg.uf, cmprr.uf) == 0) {
            existe_uf = 1;
        }
    }
    fclose(cidades); /** Fechando o arquivo para nao dar problema de seguimento **/


    /**
     * Gravando os dados da variavel reg (registro) no meu arquivo cadastros.txt
     * Condicionais para abrir o arquivo apenas SE todas forem validadas(CPF, nome, sexo, data, cidade, uf)
    **/
    if (cpf_valido == 1) {
        if (existe_cpf == 0) {
            if (nome_valido == 1) {
                if (sexo_valido == 1) {
                    if (data_valida == 1) {
                        if (existe_cidade == 1) {
                            if (existe_uf == 1) {
                                if (arquivo != NULL) {
                                    arquivo = fopen("cadastros.txt", "a");
                                    /**
                                     * Se nao der erro na abertura, entao...
                                     * Salvando os dados digitados no meu arquivo "cadastros.txt"
                                	**/
                                    fprintf(arquivo, "%s\n", reg.cpf);
                                    fprintf(arquivo, "%s\n", reg.nome);
                                    fprintf(arquivo, "%c\n", reg.sexo);
                                    fprintf(arquivo, "%d\n", reg.dia);
                                    fprintf(arquivo, "%d\n", reg.mes);
                                    fprintf(arquivo, "%d\n", reg.ano);
                                    fprintf(arquivo, "%s\n", reg.cidade);
                                    fprintf(arquivo, "%s\n", reg.uf);
                                    printf("Sucesso no cadastro da pessoa!\n");
                                    fclose(arquivo);
                                }
                            } else {
                                printf("\nUF invalida. Nao foi possivel conlcuir o cadastro.\n\n");
                            }
                        } else {
                            printf("\nCidade invalida. Nao foi possivel concluir o cadastro\n\n");
                        }
                    } else {
                        printf("\nData invalida. Nao foi possivel concluir o cadastro.\n\n");
                    }
                } else {
                    printf("\nSexo invalido. Nao foi possivel concluir o cadastro.\n\n");
                }
            } else {
                printf("\nNome invalido. Nao foi possivel concluir o cadastro.\n\n");
            }
        } else {
            printf("\nCPF ja existente. Nao foi possivel concluir o cadastro.\n\n");
        }
    } else {
        printf("\nCPF invalido. Nao foi possivel concluir o cadastro.\n\n");
    }
    hub();
}

/**.................................. Funcao para consultar pessoa ....................................................**/
void consultar_pessoa() {
    FILE *arquivo;
    char linha[TAM_MAX_LINHAS];
    char cpf[TAM_CPF];
    int encontrado = 0;
    int i = 0;
    int cpf_valido = 0;
    int teste = 4;
    long int tamanho;

    /**
     * Declarando minha funcao 'tem_cadastros' explicitamente
    **/


    if (tem_cadastros() == 1) {
        printf("Informe o CPF cadastrado (000.000.000-00): ");
        limpar_buffer();
        scanf(" %[^\n]",cpf);
        limpar_tela();
        /** Verificando se o CPF eh valido e retornando 1 (valido) e 0 (invalido) **/
        arquivo = fopen("cadastros.txt", "r");
        int verificador = verificar_cpf(cpf);
        if (verificador == 1) {
            cpf_valido = 1;
        }
        if (cpf_valido == 1) {
            printf("Dados cadastrados: \n\n");
            i = 0;
            while (fgets(linha, TAM_MAX_LINHAS, arquivo) != NULL) { /** Lendo cada linha do meu arquivo **/
                if (strstr(linha, cpf)) {           /** Apontando para a linha se o CPF lido for igual a linha lida **/
                    printf("%s", linha);
                    encontrado = 1;
                    i = 7;                          /** i = 7 pois lendo 6 vezes ele para na cidade, sem imprimir a UF **/
                } else if (encontrado && i > 0) {   /** Repeticao para imprimir todos os dados apos encontrar o CPF **/
                    printf("%s", linha);
                    i--;
                } else if (encontrado && i == 0) {  /** Finalizando a repeticao quando i = 0, que no caso seria a UF **/
                    break;
                } else {                            /** Continuando o while loop em caso da linha lida nao ser igual ao CPF digitado **/
                    continue;
                }
            }
        }
        fclose(arquivo);
        if (encontrado <= 0 || cpf_valido == 0) {
            printf("CPF %s nao encontrado no sistema.\n\n", cpf);
        }
    } else {
        printf("Nao existem cadastros no sistema.\n\n");
    }
    hub();
}

/**.................................. Funcao para listar pessoas por cidade ..............................................**/
void listar_pessoas_cidade() {
    FILE *cidades;
    FILE *arquivo;
    PESSOA cmpr;
    CIDADES cmprr;
    char nomes[TAM_NOME][TAM_MAX_LINHAS];
    char cidade[TAM_CIDADE];
    int contador = 0;
    int existe_cidade = 0;
    int i;

    if (tem_cadastros() == 1) {
        printf("Digite a cidade: ");
        limpar_buffer();
        scanf(" %[^\n]", cidade);
        limpar_tela();
        /** Verificando para saber se ja ha uma cidade igual a digitada no meu arquivo "uf_cidades.txt" **/
        cidades = fopen("uf_cidades.txt", "r");

        while ( !feof(cidades)) {
            fscanf(cidades, " %[^\n]\n", cmprr.codigo);
            fscanf(cidades, " %[^\n]\n", cmprr.uf);
            fscanf(cidades, " %[^\n]\n", cmprr.cidade_com_acento);
            fscanf(cidades, " %[^\n]\n", cmprr.cidade_sem_acento);
            capitalizar(cidade);
            capitalizar(cmprr.cidade_sem_acento);
            /** Checando se a cidade que li eh igual ao que foi digitado **/
            if (strcmp(cidade, cmprr.cidade_sem_acento) == 0) {
                existe_cidade = 1;
            }
        }
        fclose(cidades); /** Fechando o arquivo para nao dar problema de seguimento **/

        if (existe_cidade == 1) {
            arquivo = fopen("cadastros.txt", "r");
            while ( !feof(arquivo)) {
                fscanf(arquivo, "%[^\n]\n", cmpr.cpf);
                fscanf(arquivo, "%[^\n]\n", cmpr.nome);
                fscanf(arquivo, "%c\n\n", &cmpr.sexo);
                fscanf(arquivo, "%d\n\n", &cmpr.dia);
                fscanf(arquivo, "%d\n\n", &cmpr.mes);
                fscanf(arquivo, "%d\n\n", &cmpr.ano);
                fscanf(arquivo, "%[^\n]\n", cmpr.cidade);
                fscanf(arquivo, "%[^\n]\n", cmpr.uf);
                capitalizar(cidade);
                capitalizar(cmpr.cidade);
                /**
                 * 1° Checando se a cidade que li eh igual a que foi digitada
                 * 2° Atribuindo uma posicao para cada nome
                **/
                if (strcmp(cidade, cmpr.cidade) == 0) {
                    strcpy(nomes[contador], cmpr.nome);
                    contador++;
                }
            }
            if (contador == 1) {
                printf("Existe %d pessoa cadastrada na cidade de %s:\n\n", contador, cidade);
            } else {
                printf("Existem %d pessoas cadastradas na cidade de %s:\n\n", contador, cidade);
            }

            /** Organizando por ordem alfabetica os nomes por meio do qsort **/
            qsort(nomes, contador, sizeof(char) * TAM_MAX_LINHAS, (int (*)(const void *, const void *))strcmp);
            for (int i = 0; i < contador; i++) {
                printf("%s\n", nomes[i]);
            }
            fclose(arquivo);
        } else {
                printf("Cidade nao encontrada.\n\n");
            }
    } else {
        printf("Nao existem cadastros no sistema.\n\n");
    }
    hub();
}

/**.................................. Funcao para gerar relatorio ..........................................................**/
void gerar_relatorio () {
    FILE *arquivo;  /** Aponta para o arquivo que sera aberto **/
    PESSOA ler;    /** Variavel do tipo struct PESSOA **/
    int idade, ano;
    float total_pessoas = 0, pessoas0_15 = 0, pessoas16_29 = 0, pessoas30_49 = 0, pessoas50_60 = 0, pessoasAcima_60 = 0;
    float percentual0_15, percentual16_29, percentual30_49, percentual50_60, percentualAcima_60;
    float sexo_masculino = 0, sexo_feminino = 0;
    float percentual_masculino, percentual_feminino;

    if (tem_cadastros() == 1) {
        limpar_buffer();
        arquivo = fopen("cadastros.txt", "r");
            while ( !feof(arquivo)) {
                fscanf(arquivo, "%[^\n]\n", ler.cpf);
                fscanf(arquivo, "%[^\n]\n", ler.nome);
                fscanf(arquivo, "%c\n\n", &ler.sexo);
                fscanf(arquivo, "%d\n\n", &ler.dia);
                fscanf(arquivo, "%d\n\n", &ler.mes);
                fscanf(arquivo, "%d\n\n", &ler.ano);
                fscanf(arquivo, "%[^\n]\n", ler.cidade);
                fscanf(arquivo, "%[^\n]\n", ler.uf);

                total_pessoas++;
                ano = ano_atual();
                idade = ano - ler.ano;
                if (idade >= 0  && idade <= 15) {
                    pessoas0_15++;
                } else if (idade >= 16 && idade <= 29) {
                    pessoas16_29++;
                } else if (idade >= 30 && idade <= 49) {
                    pessoas30_49++;
                } else if (idade >= 50 && idade <= 60) {
                    pessoas50_60++;
                } else if (idade >= 60 && idade <= 120) {
                    pessoasAcima_60++;
                }
                if (ler.sexo == 'M') {
                    sexo_masculino++;

                } else if (ler.sexo == 'F') {
                    sexo_feminino++;
                }
            }
            fclose(arquivo);

            // Calculando os percentuais
            percentual0_15 = pessoas0_15 / total_pessoas * 100;
            percentual16_29 = pessoas16_29 / total_pessoas * 100;
            percentual30_49 = pessoas30_49 / total_pessoas * 100;
            percentual50_60 = pessoas50_60 / total_pessoas * 100;
            percentualAcima_60 = pessoasAcima_60/ total_pessoas * 100;

            percentual_masculino = sexo_masculino / total_pessoas * 100;
            percentual_feminino = sexo_feminino / total_pessoas * 100;

            // Imprimindo o relatorio
            printf("Total de pessoas beneficiadas pelo SGBS: %.0f\n\n", total_pessoas);
            printf("Percentual de pessoas por faixa etaria:\n");
            printf("0 a 15 anos............: %.2f%%\n", percentual0_15);
            printf("16 a 29 anos...........: %.2f%%\n", percentual16_29);
            printf("30 a 49 anos...........: %.2f%%\n", percentual30_49);
            printf("50 a 60 anos...........: %.2f%%\n", percentual50_60);
            printf("Acima de 60 anos.......: %.2f%%\n", percentualAcima_60);

            printf("\nPercentual de pessoas por sexo:\n");
            printf("Masculino.............: %.2f%%\n", percentual_masculino);
            printf("Feminino..............: %.2f%%\n", percentual_feminino);
    } else {
        printf("Nao existem cadastros no sistema.\n\n");
    }
}

/**.................................. Funcao para excluir pessoa ......................................................**/
void excluir_pessoa () {
    FILE *arquivo;  /** Aponta para o arquivo que sera aberto **/
    FILE *temp_arquivo; /** Aponta para o arquivo temporario que sera criado **/
    PESSOA cadastro;    /** Variavel do tipo struct PESSOA **/
    char cpf_busca[TAM_CPF];
    int existe_cpf;
    int opcao;

    if (tem_cadastros() == 1) {
        printf("Digite o CPF que deseja excluir (000.000.000-00): ");
        limpar_buffer();
        scanf(" %[^\n]", cpf_busca);

        /** Verificando para saber se ha um CPF igual ao digitado no meu arquivo "cadastros.txt" **/
        arquivo = fopen("cadastros.txt", "r");
        temp_arquivo = fopen("temp_cadastros.txt", "w"); /** Criando o arquivo temporario para os cadastros **/
        if (arquivo != NULL && temp_arquivo != NULL){
            existe_cpf = 0;
            while ( !feof(arquivo)) {
                fscanf(arquivo, "%[^\n]\n", cadastro.cpf);
                fscanf(arquivo, "%[^\n]\n", cadastro.nome);
                fscanf(arquivo, "%c\n\n", &cadastro.sexo);
                fscanf(arquivo, "%d\n\n", &cadastro.dia);
                fscanf(arquivo, "%d\n\n", &cadastro.mes);
                fscanf(arquivo, "%d\n\n", &cadastro.ano);
                fscanf(arquivo, "%[^\n]\n", cadastro.cidade);
                fscanf(arquivo, "%[^\n]\n", cadastro.uf);

                /** Checando se o CPF que li eh igual ao digitado **/
                if (strcmp(cpf_busca, cadastro.cpf) == 0) {
                    existe_cpf = 1;
                    continue;
                }
                /** Copiando todos os dados de CPF's diferentes do que foi digitado para o arquivo temporario **/
                fprintf(temp_arquivo, "%s\n", cadastro.cpf);
                fprintf(temp_arquivo, "%s\n", cadastro.nome);
                fprintf(temp_arquivo, "%c\n", cadastro.sexo);
                fprintf(temp_arquivo, "%d\n", cadastro.dia);
                fprintf(temp_arquivo, "%d\n", cadastro.mes);
                fprintf(temp_arquivo, "%d\n", cadastro.ano);
                fprintf(temp_arquivo, "%s\n", cadastro.cidade);
                fprintf(temp_arquivo, "%s\n", cadastro.uf);
            }
            fclose(arquivo); /** Fechando os arquivos **/
            fclose(temp_arquivo);
            limpar_tela();
            if (existe_cpf == 1) {
                printf("Tem certeza que deseja excluir o CPF %s?\n\nDigite 1 para confirmar ou 2 para cancelar: ", cpf_busca);
                scanf("%d", &opcao);
                if (opcao == 1) {
                    limpar_tela();
                    /**
                     * 1° Excluindo o arquivo "cadastros.txt" antigo
                     * 2° Renomeando o arquivo "temp_cadastros.txt" para "cadastros.txt"
                    **/
                    remove("cadastros.txt");
                    rename("temp_cadastros.txt", "cadastros.txt");
                    printf("CPF %s excluido com sucesso!\n", cpf_busca);
                }
            }else {
                limpar_tela();
                remove("temp_cadastros.txt");
                printf("CPF %s não encontrado.\n", cpf_busca);
            }
        }
    } else {
        printf("Nao existem cadastros no sistema.\n\n");
    }
        hub();
}

/**.................................. Declarando funcoes que serao utilizadas dentro das funcoes principais acima..............**/
int ano_atual () {
    /**       ** Funcao para pegar o ano atual baseando-se na data do computador **       **/

    int ano;
    /**
     * A funcao time() obtem a hora atual como um 'time_t'
     * 'time_t' representa o numero de segundos desde as 00:00 de 01/jan de 1970 ("tempo UNIX" || marco zero do sistema operacional UNIX)
     * 'NULL' eh utilizado para que a hora atual seja retornada
    **/
    time_t now = time(NULL);
    /**
     * localtime() converte 'time_t' numa struct 'tm', que contem dados como dia, ano, mes, horas, minutos e segundos
     * o ponteiro 't' eh utilizado para armazenar o endereco da struct 'tm', que foi retornada pela funcao localtime()
    **/
    struct tm *t = localtime(&now);
    /**
     * Utilizando 't -> tm_year' para acessar o campo 'tm_year' da struct 'tm', apontada por '*t'
     * A variavel 'tm_year' contem o numero de anos desde 1900, por isso somamos +1900
     * Atribuindo ao int 'ano' e retornando o valor
    **/
    ano = t -> tm_year + 1900;
    return ano;
}

int tem_cadastros () {
    FILE *arquivo;
    int tem_cadastros = 0;
    long int tamanho = 0;

    arquivo = fopen("cadastros.txt", "r");
    if (arquivo == NULL) {
        tem_cadastros = 0;
    } else {
        fseek(arquivo, 0 , SEEK_END);
        tamanho = ftell(arquivo);
        if (tamanho == 0) {
            tem_cadastros = 0;
        } else {
            tem_cadastros = 1;
            }
        fclose(arquivo);
    }
    return tem_cadastros;
}



char maiusculo(char str[]) {
    int i, tam_str;

    /**
     * 1° Pegando o tamanho total da minha string
     * 2° Percorrendo toda a string ate o fim e trocando todas as letras por maiusculas
    **/
    tam_str = strlen(str);
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    return str[TAM_MAX];
}

void hub() {
    int opcao_fim;

    printf("\nDigite 0 para voltar ao menu\n");
    scanf("%d", &opcao_fim);
}

int verificar_cpf(char cpf[]) {
    int cpf_novo[TAM_CPF], tot_d1 = 0, tot_d2 = 0, i = 0, a = 0;
    int digito_calculado, digito_usuario, tam_cpf, cpf_valido;
    /**
     * Verificando validez do CPF e existencia dupla

     * 1) Verificando se o CPF eh valido e retornando cpf_valido = 1 (valido) ou cpf_valido = 0 (invalido)
    **/
    tam_cpf = strlen(cpf);
    if(strlen(cpf) != 14) {
        cpf_valido = 0;
    }
    else if((strcmp(cpf,"000.000.000-00") == 0) || (strcmp(cpf,"111.111.111-11") == 0) || (strcmp(cpf,"222.222.222-22") == 0) ||
            (strcmp(cpf,"333.333.333-33") == 0) || (strcmp(cpf,"444.444.444-44") == 0) || (strcmp(cpf,"555.555.555-55") == 0) ||
            (strcmp(cpf,"666.666.666-66") == 0) || (strcmp(cpf,"777.777.777-77") == 0) || (strcmp(cpf,"888.888.888-88") == 0) ||
            (strcmp(cpf,"999.999.999-99") == 0)) {
        cpf_valido = 0;
    }
    else {
        /** Pegando todos os caracteres que nao sejam ponto ou traco**/
        for (i = 0; i <= tam_cpf; i++) {
            if (cpf[i] != '.' && cpf[i] != '-') {
                cpf_novo[a] = cpf[i] - 48;
                a++;
            }
        }
        for (i = 0; i < 9; i++) {
            tot_d1 = tot_d1 + ((cpf_novo[i]) * (10 - i));
            tot_d2 = tot_d2 + ((cpf_novo[i]) * (11 - i));
        }
        tot_d1 = (tot_d1 * 10) % 11;
        if (tot_d1 > 9) {
            tot_d1 = 0;
        }
        tot_d2 = (tot_d2 + (tot_d1 * 2)) * 10 % 11;
        if (tot_d2 > 9) {
            tot_d2 = 0;
        }

        digito_calculado = (tot_d1 * 10) + tot_d2;
        i = cpf_novo[9];
        a = cpf_novo[10];
        digito_usuario = ((i) * 10) + (a);
        cpf_valido = 0;
        if (digito_calculado == digito_usuario) {
            cpf_valido = 1;
        }
    }
    return cpf_valido;
}

int verificador_data(int dia, int mes, int ano) {
    /**
     * return 0 == invalido
     * return 1 == valido

     * Verificando se o mês eh válido
    **/
    if (mes < 1 || mes > 12) {
        return 0;
    }
    /** Verificando se o dia é válido **/
    if (dia < 1) {
        return 0;
    }
    /** Atribuindo os dias de cada mês **/
    int dias_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
        /** Atribuindo 29 dias a fevereiro, caso o ano seja bissexto **/
        dias_mes[1] = 29;
    }
    /** Verificando se o dia nao eh maior que os dias do mes digitado**/
    if (dia > dias_mes[mes]) {
        return 0;
    }
    /** Verificando se o ano eh válido **/
    if (ano < 0 && ano > 9999) {
        return 0;
    }
    return 1;
}

int verificador_letras(char *nome){
    int i;

    i = 0;
    while (nome[i] != '\0') {
        if (!isalpha(nome[i]) && nome[i] != ' ') { /** percorre todos os caracteres **/
            return 0; /** retorna 0 se nao houverem apenas letras **/
        } i++;
    }
    return 1; /** retorna 1 se houverem apenas letras **/
}

void limpar_buffer() {
    /**
		Essa funcao serve para limpar o buffer
        possibilitando que uma string seja lida
        sem que haja lixo armazenado
    **/
    char gc;
    while ((gc = getchar()) != '\n' && gc != EOF);
}

void pause() {
    #if defined(_WIN32) || defined(_WIN64)
        printf("Console encerrado.\n");
        system("pause");
    #endif

    #if defined(linux) || defined(APPLE) || defined(unix)
        printf("Console encerrado.\n");
        system("read");
    #endif
}

void limpar_tela() {
    /** Para manter o console limpo enquanto o usuario navega pela aplicacao **/
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif

    #if defined(linux) || defined(APPLE) || defined(unix)
        system("clear");
    #endif
}

void capitalizar (char *str) {
    int tamanho;
    int i;
    int espaco = 1;

    tamanho = strlen(str);

    for (i = 0; i < tamanho; i++) {
        /**1° Capitalizando a primeira letra da frase
         * 2° Caso a funcao ache um espaco ela capitaliza o proximo caractere (implicitamente dizendo que logo apos o espaco havera uma letra)
         * 3° Caso nao seja um espaco, a funcao transforma todo o resto em minusculo
         * 4° Repete ate que i == tamanho - 1
        **/
        if (espaco == 1 && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            espaco = 0;
        } else if (isspace(str[i])) {
            espaco = 1;
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

