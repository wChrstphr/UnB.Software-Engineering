#include <stdio.h>

int main(){
    char menu;
    float c, f;

    printf("Menu:\nC - Fahrenheit para Celsius\n"
    "F - Celsius para Fahrenheit\n"
    "S - Sair\n");

    scanf("%c", &menu);
    switch (menu)
    {
    case 'C':
        printf("Digite o valor a ser convertido:\n");
        scanf("%f", &c);
        f = c * 1.8 + 32;
        printf("Valor convertido, %.1f (Celsius) para %.1f (Fahrenheit)", c,f);
        break;
    case 'F':
        printf("Digite o valor a ser convertido:\n");
        scanf("%f", &f);
        c = (f - 32) / 1.8;
        printf("Valor convertido, %.1f (Fahrenheit) para %.1f (Celsius)", f,c);
        break;
    case 'S':
        printf("Obrigado por usar nosso conversor!\n");
        break;
    }
    return 0;
}