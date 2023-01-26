#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAM_MAX_LINHAS 101
#define TAM_CODIGO 7
#define TAM_CPF 15
#define TAM_NOME 101
#define TAM_CIDADE 35 //Pelo municipio Vila Bela da Santissima Trindade
#define TAM_UF 3
#define TAM_UF_VERIFICACAO 2
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

//Declarando um struct, que eh uma estrutura heterogenea (como um registro) para o tipo pessoa
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


void limpar_buffer() {
    // Essa funcao serve para limpar o buffer
    // possibilitando que uma string seja lida
    // sem que haja lixo armazenado
    char gc;
    while ((gc = getchar()) != '\n' && gc != EOF);
}

void pause() {
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif

    #if defined(linux) || defined(APPLE) || defined(unix)
        system("read");
    #endif
}

void limpar_tela() {
    // Para manter o console limpo enquanto o usuario navega pela aplicacao
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif

    #if defined(linux) || defined(APPLE) || defined(unix)
        system("clear");
    #endif
}

void menu() {
    printf("1) Cadastrar Pessoa\n");
    printf("2) Consultar Pessoa\n");
    printf("3) Listar pessoas por Cidade\n");
    printf("4) Gerar relatorio\n");
    printf("5) Excluir Pessoa\n");
    printf("6) Encerrar Programa\n");
}

void cadastrar_pessoa() {
    // Variaveis
    FILE *arquivo;  //Aponta para o arquivo que sera aberto
    FILE *cidades;
    PESSOA reg;     // Variavel do tipo struct pessoa para registrar
    PESSOA cmpr; // Variavel do tipo struct pessoa para comparar
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


    // Instrucoes e entrada de dados
    limpar_buffer(); // Para ler uma string sem que haja lixo no buffer de entrada de dados
    printf("Digite o CPF: ");
    scanf("%[^\n]", reg.cpf);

    // Verificando validez do CPF e existencia dupla
    // 1) Verificando se o CPF eh valido e retornando 1 (valido) e 0 (invalido)
    cpf_valido = 0;
    int verificador = verificar_cpf(reg.cpf);
    if (verificador == 1) {
        cpf_valido = 1;
    }
    // 2) Verificando para saber se ja ha um CPF igual ao digitado no meu arquivo "cadastros.txt"

    arquivo = fopen("cadastros.txt", "r"); // Abrindo o arquivo
    existe_cpf = 0;

    // while (NOT(!) end of file)
    while ( !feof(arquivo)) {
        fscanf(arquivo, "%[^\n]\n", cmpr.cpf);
        fscanf(arquivo, "%[^\n]\n", cmpr.nome);
        fscanf(arquivo, "%c\n\n", &cmpr.sexo);
        fscanf(arquivo, "%d\n\n", &cmpr.dia);
        fscanf(arquivo, "%d\n\n", &cmpr.mes);
        fscanf(arquivo, "%d\n\n", &cmpr.ano);
        fscanf(arquivo, "%[^\n]\n", cmpr.cidade);
        fscanf(arquivo, "%[^\n]\n", cmpr.uf);

        // Checando se o CPF que li eh igual ao que digitado
        if (strcmp(reg.cpf, cmpr.cpf) == 0) {
            existe_cpf = 1;
        }
    } fclose(arquivo); // Fechando o arquivo para nao dar problema de seguimento

    limpar_buffer();
    printf("Digite o nome completo: ");
    scanf("%[^\n]", reg.nome);

    // Verificando se foram digitados apenas letras para a varivel reg.nome
    nome_valido = 0;
    if (verificador_letras(reg.nome) == 1) {
       nome_valido = 1;
    }

    limpar_buffer();
    printf("Digite o sexo: ");
    scanf("%c", &reg.sexo);
    sexo_valido = 0;
    if (reg.sexo == 'M' || reg.sexo == 'm'|| reg.sexo == 'F' || reg.sexo == 'f') {
        sexo_valido = 1;
    }
    printf("Digite o dia de nascimento: ");
    scanf("%d", &reg.dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &reg.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &reg.ano);
    // Verificando se a data digitada eh uma data valida
    data_valida = 0;
    if (verificador_data(reg.dia, reg.mes, reg.ano) == 1) {
        data_valida = 1;
    }
    printf("Digite a cidade: ");
    limpar_buffer();
    scanf("%[^\n]", reg.cidade);

    //  Verificando para saber se ja ha uma cidade igual a digitada no meu arquivo "uf_cidades.txt"

    cidades = fopen("uf_cidades.txt", "r"); // Abrindo o arquivo
    existe_cidade = 0;

    // while (NOT(!) end of file)
    while ( !feof(cidades)) {
        fscanf(cidades, "%[^\n]\n", cmprr.codigo);
        fscanf(cidades, "%[^\n]\n", cmprr.uf);
        fscanf(cidades, "%[^\n]\n", cmprr.cidade_com_acento);
        fscanf(cidades, "%[^\n]\n", cmprr.cidade_sem_acento);
        maiusculo(reg.cidade);
        maiusculo(cmprr.cidade_sem_acento);
        // Checando se a cidade que li eh igual ao que foi digitado
        if (strcmp(reg.cidade, cmprr.cidade_sem_acento) == 0) {
            existe_cidade = 1;
        }
    }
    fclose(cidades); // Fechando o arquivo para nao dar problema de seguimento
    printf("Digite a UF: ");
    limpar_buffer();
    scanf("%[^\n]", reg.uf);
    //  Verificando para saber se ja ha uma UF igual a digitada no meu arquivo "uf_cidades.txt"

    cidades = fopen("uf_cidades.txt", "r"); // Abrindo o arquivo
    existe_uf = 0;

    // while (NOT(!) end of file)
    while ( !feof(cidades)) {

        char line[TAM_MAX_LINHAS];
        fgets(line, TAM_MAX_LINHAS, cidades);
        strncpy(cmprr.codigo, line, TAM_CODIGO);
        fgets(line, TAM_MAX_LINHAS, cidades);
        strncpy(cmprr.uf, line, TAM_UF_VERIFICACAO);
        fgets(line, TAM_MAX_LINHAS, cidades);
        strncpy(cmprr.cidade_com_acento, line, strlen(reg.cidade));
        fgets(line, TAM_MAX_LINHAS, cidades);
        strncpy(cmprr.cidade_sem_acento, line, strlen(reg.cidade));


        maiusculo(reg.uf);
        maiusculo(cmprr.uf);
        // Checando se a UF que li eh igual ao que foi digitado
        if (strcmp(reg.uf, cmprr.uf) == 0) {
            existe_uf = 1;
        }
    }
    fclose(cidades); // Fechando o arquivo para nao dar problema de seguimento




    // Gravando os dados da variavel reg (registro) no meu arquivo cadastros.txt
    // Condicional para abrir o arquivo apenas SE nao existir o CPF digitado na minha base de dados
    if (cpf_valido == 1) {
        if (existe_cpf == 0) {
            if (nome_valido == 1) {
                if (sexo_valido == 1) {
                    if (data_valida == 1) {
                        if (existe_cidade == 1) {
                            if (existe_uf == 1) {
                                if (arquivo != NULL) {
                                    arquivo = fopen("cadastros.txt", "a");
                                    // Se nao der erro na abertura, entao...
                                    // Salvando os dados digitados no meu arquivo(aberto)
                                    fprintf(arquivo, "%s\n", reg.cpf);
                                    fprintf(arquivo, "%s\n", reg.nome);
                                    fprintf(arquivo, "%c\n", reg.sexo);
                                    fprintf(arquivo, "%d\n", reg.dia);
                                    fprintf(arquivo, "%d\n", reg.mes);
                                    fprintf(arquivo, "%d\n", reg.ano);
                                    fprintf(arquivo, "%s\n", reg.cidade);
                                    fprintf(arquivo, "%s\n", reg.uf);
                                    printf("Sucesso no cadastro da pessoa!\n");

                                    // Fechamento do arquivo
                                    fclose(arquivo);
                                }
                            } else {
                                printf("UF invalida. Nao foi possivel conlcuir o cadastro.\n\n");
                            }
                        } else {
                            printf("Cidade invalida. Nao foi possivel concluir o cadastro\n\n");
                        }
                    } else {
                        printf("Data invalida. Nao foi possivel concluir o cadastro.\n\n");
                    }
                } else {
                    printf("Sexo invalido. Nao foi possivel concluir o cadastro.\n\n");
                }
            } else {
                printf("Nome invalido. Nao foi possivel concluir o cadastro.\n\n");
            }
        } else { // Caso o CPF exista, entao...
            printf("CPF ja existente. Nao foi possivel concluir o cadastro.\n\n");
        }
    } else { // Caso o CPF seja invalidodo pela funcao
        printf("CPF invalido. Nao foi possivel concluir o cadastro.\n\n");
    }
    hub();
}

int verificador_letras(char *nome){
    int i;


    i = 0;
    while (nome[i] != '\0') {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0;
        } i++;
    }
    return 1;


    /**
    for (i = 0; texto[i] != '\0'; ++i){ //percorrer todos os carateres
        if (!isalpha(texto[i]) && texto[i] != ' '){ //se não for letra nem espaço
            return 0; //retornar 0 indicando que não tem somente letras
        }
    }
    return 1; //retornar 1 indica que só tem letras
     **/

}

int verificador_data(int dia, int mes, int ano) {

    /** return 0 == invalido
        return 1 == valido **/

    // Verificando se o mês é válido
    // Retorna 0 se for invalido
    if (mes < 1 || mes > 12) {
        return 0;
    }


    // Verificando se o dia é válido
    if (dia < 1) {
        return 0;
    }

    int dias_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
        dias_mes[1] = 29;
    }
    if (dia > dias_mes[mes - 1]) {
        return 0;
    }

    // Verificando se o ano é válido
    if (ano < 0) {
        return 0;
    }
    return 1;
}

// Funcao para consultar pessoa
/**void consultar_pessoa() {
    FILE *arquivo;
    int cpf_valido;
    char cpf[TAM_CPF];

    limpar_buffer(); // Para ler uma string sem que haja lixo no buffer de entrada de dados
    printf("Digite o CPF: ");
    scanf(" %s", cpf);


    int verificador = verificar_cpf(cpf);
    if (verificador == 1) {
        printf("CPF valido\n\n");
    } else {
        printf("CPF invalido\n\n");
    }
    hub();
}
**/
int verificar_cpf(char cpf[]) {
    int cpf_novo[TAM_CPF], tot_d1 = 0, tot_d2 = 0, digito_calculado, digito_usuario, i, a = 0, tam;
    int cpf_valido;


    // Verificando validez do CPF e existencia dupla
    // 1) Verificando se o CPF eh valido e retornando 1 (valido) e 0 (invalido)
    tam = strlen(cpf);
    if(strlen(cpf) != 14) {
        cpf_valido = 0;
    }
    else if((strcmp(cpf,"000.000.000-00") == 0) || (strcmp(cpf,"111.111.111-11") == 0) || (strcmp(cpf,"222.222.222-22") == 0) ||
            (strcmp(cpf,"333.333.333-33") == 0) || (strcmp(cpf,"444.444.444-44") == 0) || (strcmp(cpf,"555.555.555-55") == 0) ||
            (strcmp(cpf,"666.666.666-66") == 0) || (strcmp(cpf,"777.777.777-77") == 0) || (strcmp(cpf,"888.888.888-88") == 0) ||
            (strcmp(cpf,"999.999.999-99") == 0)) {
        cpf_valido = 0; ///se o CPF tiver todos os números iguais ele é inválido.
    }
    else {

        for (i = 0; i <= tam; i++) {
            if (cpf[i] != '.' && cpf[i] != '-') {
                cpf_novo[a] = cpf[i] - 48;
                a++;
            }
        }

    /**
        while (i <= tam) {
            if(reg.cpf[i] != '.' && reg.cpf[i] != '-') {
                cpf_novo[a] = reg.cpf[i] - 48;
                a++;
           } i++;
    }
    **/

        for (i = 0; i < 9; i++) {
            tot_d1 = tot_d1 + ((cpf_novo[i]) * (10 - i));
            tot_d2 = tot_d2 + ((cpf_novo[i]) * (11 - i));
        }

    /**
        i=0;
        while (i < 9) {
            tot_d1 = tot_d1 + ((cpf_novo[i]) * (10 - i));
            tot_d2 = tot_d2 + ((cpf_novo[i]) * (11 - i));
            i++;
        }
    **/

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

void hub() {
    int opcao_fim;
    printf("Digite 1 para voltar ao menu\n");

    scanf("%d", &opcao_fim);
}


void verificar_cidade(char cidade[]){

}

char maiusculo(char str[]) {
    int i, tam_str;
    
    tam_str = strlen(str);
    
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    return str[TAM_CIDADE];
}

void consultar_pessoa() {
    FILE *arquivo = fopen("cadastros.txt", "r");
    char linha[TAM_MAX_LINHAS];
    char cpf[TAM_CPF];
    int encontrado = 0;
    int i;
    int cpf_valido;

    printf("Informe o CPF cadastrado: ");
    scanf("%s",cpf);

    // Verificando se o CPF eh valido e retornando 1 (valido) e 0 (invalido)
    cpf_valido = 0;
    int verificador = verificar_cpf(cpf);
    if (verificador == 1) {
        cpf_valido = 1;
    }
    if (cpf_valido == 1) {
        i = 0;
        while (fgets(linha, TAM_MAX_LINHAS, arquivo) != NULL) { // Lendo cada linha do meu arquivo
            if (strstr(linha, cpf)) { // Apontando para a linha se o CPF lido for igual a linha lida
                printf("%s", linha);
                encontrado = 1;
                i = 7; // i = 7 pois lendo 6 vezes ele para na cidade, sem imprimir a UF
            } else if (encontrado && i > 0) { // Repeticao para imprimir todos os dados apos encontrar o CPF
                printf("%s", linha);
                i--;
            } else if (encontrado && i == 0) { // Finalizando a repeticao quando i = 0, que no caso seria a UF
                break;
            } else { // Continuando o while loop em caso da linha lida nao ser igual ao CPF digitado
                continue;
            }
        }
    }
    if (encontrado <= 0 || cpf_valido == 0) {
        printf("CPF nao encontrado no sistema.\n\n");
    }
    printf("\n\n");
    fclose(arquivo);
    hub();
}

void listar_pessoas_cidade() {
    FILE *cidades;
    CIDADES cmprr;
    char cidade[TAM_CIDADE];
    int existe_cidade;
    
    printf("Digite a cidade: ");
    limpar_buffer();
    scanf(" %[^\n]", cidade);

    //  Verificando para saber se ja ha uma cidade igual a digitada no meu arquivo "uf_cidades.txt"

    cidades = fopen("uf_cidades.txt", "r"); // Abrindo o arquivo
    existe_cidade = 0;

    // while (NOT(!) end of file)
    while ( !feof(cidades)) {
        fscanf(cidades, " %[^\n]\n", cmprr.codigo);
        fscanf(cidades, " %[^\n]\n", cmprr.uf);
        fscanf(cidades, " %[^\n]\n", cmprr.cidade_com_acento);
        fscanf(cidades, " %[^\n]\n", cmprr.cidade_sem_acento);
        maiusculo(cidade);
        maiusculo(cmprr.cidade_sem_acento);
        printf("%s\n\n", cidade);
        printf("%s\n\n", cmprr.cidade_sem_acento);
        // Checando se a cidade que li eh igual ao que foi digitado
        if (strcmp(cidade, cmprr.cidade_sem_acento) == 0) {
            existe_cidade = 1;
        }
    }
    fclose(cidades); // Fechando o arquivo para nao dar problema de seguimento
    if (existe_cidade == 1) {
        printf("A cidade existe\n\n");
    } else {
        printf("Cidade inexistente\n\n");
    }
}
