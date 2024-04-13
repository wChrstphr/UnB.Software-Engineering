#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
    char palavra[500];
    char palavra_anterior[500] = "";
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeArq);
    int pp;
    int i;

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
    fprintf(arqsaida, "]");

    fclose(arqent);
    fclose(arqsaida);

    return 1;
}

int main()
{
    char nomearq[30];
    printf("Entre com nome do arquivo:\n");
    scanf("%s", nomearq);

    if (!word2vec(nomearq))
        printf("\nErro na geração do vocábulo!\n");
    else
        printf("\nGerei o vocábulo!\n");

    return 0;
}