#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TAM_MAX_PALAVRA 500

int verificarRepetida(const char *palavra, const char palavras_anteriores[][TAM_MAX_PALAVRA], int contadorPalavras)
{
    // Percorrendo o array de palavras anteriores
    for (int i = 0; i < contadorPalavras; i++)
    {
        // Compara a palavra atual com cada palavra anterior no array
        if (strcmp(palavra, palavras_anteriores[i]) == 0)
        {
            // Se encontrar uma correspondente, retorna verdadeiro ( 1 )
            return 1;
        }
    }
    return 0;
}

char *remover_acento(const char *palavra) {
    char *sem_acentos = strdup(palavra); // Copia a palavra original para uma nova string
    if (sem_acentos == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    // Tabela de substituição de caracteres acentuados
    char *acentos = "áàâãéèêíìîóòôõúùûçÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇ";
    char *sem_acentos_substitutos = "aaaaeeeiiioooouuucAAAAEEEIIIOOOOUUUC";
    int tamanho = strlen(sem_acentos);

    // Substituir cada caractere acentuado por seu equivalente sem acento
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; acentos[j] != '\0'; j++) {
            if (sem_acentos[i] == acentos[j]) {
                sem_acentos[i] = sem_acentos_substitutos[j];
                break; // Interrompe o loop quando encontrar um caractere acentuado
            }
        }
    }

    return sem_acentos;
}

int namefilepointposition(char *fullname)
{
    int i;
    for (i = 0; i < strlen(fullname); i++)
    {
        if (fullname[i] == '.')
            break;
    }
    if (i >= strlen(fullname))
        return -1;
    else
        return i;
}

int word2vec(char *pNomeArq)
{
    FILE *arqent, *arqsaida;
    char *palavras_tokenizadas;
    char palavra[500] = "";
    char palavras_anteriores[500][TAM_MAX_PALAVRA];
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeArq);
    int pp;
    int i;
    int tamanho;
    int contadorPalavras = 0;

    // Generating Output filename
    if (pointidx >= 0)
    {
        for (pp = 0; pp < pointidx; pp++)
            nomarq[pp] = pNomeArq[pp];
        nomarq[pp] = '\0'; // End of string
    }
    else
        strcpy(nomarq, pNomeArq);

    strcat(nomarq, "_Vocabulo");
    strcat(nomarq, ".txt");
    printf("\nRecebi no nome do arquivo: %s\n", nomarq);

    // Generating the output:
    arqent = fopen(pNomeArq, "r");
    arqsaida = fopen(nomarq, "w");
    if (arqent == NULL || arqsaida == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(0);
    }
    printf("Abri o arquivo!\n");

    while (fscanf(arqent, "%s", palavra) != EOF)
    {
        int acentos = 0;
        tamanho = strlen(palavra);

        printf("\nPalavra: %s\n", palavra);
        printf("Palavra sem acento: %s", remover_acento(palavra));
        
        // Convertendo letras maiúsculas em minúsculas
        for (i = 0; palavra[i] != '\0'; i++)
        {
            palavra[i] = tolower(palavra[i]);
            if (palavra[i] >= 'a' && palavra[i] <= 'z'); else {
                acentos++;
            }
        }
        printf("Acentos: %d\n", acentos);
        
        printf("Tamanho da palavra: %d\n", tamanho);
        printf("Palavras minusculas: %s\n", palavra);
        if (tamanho > (4 + acentos) && !verificarRepetida(palavra, palavras_anteriores, contadorPalavras))
        {
            // Tokenizando palavras e armazenando no arquivo de saída
            palavras_tokenizadas = strtok(palavra, " .");
            while (palavras_tokenizadas != NULL)
            {
                printf("Palavra lida: %s\n", palavras_tokenizadas);
                fprintf(arqsaida, "%s, ", palavras_tokenizadas);
                palavras_tokenizadas = strtok(NULL, " .");
            }
            // Copiando a palavra armazenada nas palavras anteriores para verificação futura
            strcpy(palavras_anteriores[contadorPalavras], palavra);
            contadorPalavras++;
        }
    }

    /*
    fprintf(arqsaida, "[");
    while (fscanf(arqent, "%s", palavra) == 1) //passando por cada palavra
    {
        for (i = 0; palavra[i] != '\0'; i++)
        {
            palavra[i] = tolower(palavra[i]); //deixando todas as palavras em minusculo
        }
        if (strstr(palavra_anterior, palavra) == NULL) { // aqui eu vejo se existe a palavra lida na linha 55 já foi lida antes
            strcat(palavra_anterior, palavra); //aqui eu "jogo" a palavra que foi lida, e armazeno ela em palavra_anterior, para checar na linha 61
            strcat(palavra_anterior, " "); //adicionando um espaço, para que a leitura em strstr seja feita corretamente

        } else {
            fprintf(arqsaida, "%s, ", palavra);
            printf("Palavra: %s\n", palavra);
        }
    }
    */
    fclose(arqent);
    fclose(arqsaida);

    return 1;
}

int main()
{
    char nomearq[30];
    printf("Entre com nome do arquivo:\n");
    scanf("%s", nomearq);

    if (!word2vec(nomearq)) // ou "word2vec(nomearq) == 0"
        printf("\nErro na geração do vocábulo!\n");
    else
        printf("\nGerei o vocábulo!\n");

    return 0;
}