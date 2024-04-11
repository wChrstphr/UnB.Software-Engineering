

#include <stdio.h>
#include <string.h>

int namefilepointposition(char *fullname){
   int i;
   for(i=0;i<strlen(fullname);i++){
       if(fullname[i]=='.')
        break;
   } 
   if(i>=strlen(fullname))
        return -1;
    else
        return i;
}



int word2vec(char *pNomeArq){
    FILE *arqent, *arqsaida;
    char palavra[500];
    char palavras = NULL;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeArq);
    int pp;

//Generating Output filename    
    if(pointidx>=0){
        for(pp=0;pp<pointidx;pp++)
            nomarq[pp] = pNomeArq[pp];
        nomarq[pp] = '\0';//End of string
    }
    else
        strcpy(nomarq,  pNomeArq);
        
    strcat(nomarq,  "_Vocabulo");
    strcat(nomarq,  ".txt");
    printf("\nRecebi no nome do arquivo: %s", nomarq);

//Generating the output:
    arqent = fopen (pNomeArq, "r");
    arqsaida = fopen (nomarq, "w");
    if (arqent == NULL || arqsaida == NULL) {
        printf("Nao foi possivel abrir o arquivo!");
        return 0;
    } printf ("Abri o arquivo!\n");

    while (fscanf(arqent, "%s", palavra) == 1) {
        printf("Palavra lida: %s\n", palavra);
    }
    
    while (fscanf(arqent, "%s", palavra) == 1) {
        fprintf(arqsaida,"%s", palavra);
    }
    fclose(arqent);
    fclose(arqsaida);

    return 1;
}


int main()
{   
    char nomearq[30];
    printf("Entre com nome do arquivo:");
    scanf("%s",nomearq);
    
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocábulo!");
    else
        printf("\nGerei o vocábulo!\n");
    
    return 0;
}