#include <stdio.h>

#define JAN 31
#define FEV 28
#define FEV_BIS 29
#define MAR 31
#define ABR 30
#define MAI 31
#define JUN 30
#define JUL 31
#define AGO 31
#define SET 30
#define OUT 31
#define NOV 30
#define DEZ 31

int meses[] = {JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ};
int meses_bis[] = {JAN, FEV_BIS, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ};

int verificaBissexto(int *a)
{
    if (*a >= 0 && (*a % 400 == 0 || (*a % 4 == 0 && *a % 100 != 0)) && *a <= 9999)
    {
        return 1;
    }
    return 0;
}
void calculaDiaMes(int *d, int *m, int *a)
{
    int dia = 0;
    int mes = 1;
    if (verificaBissexto(a))
    {
        if (*d <= 366 && *d >= 1 && *a >= 1)
        {
            for (int i = 0; i < sizeof(meses_bis) / sizeof(meses_bis[0]); i++)
            {
                if (*d > meses_bis[i])
                {
                    mes++;
                    *d -= meses_bis[i];
                }
                else
                {
                    dia = *d;
                    break;
                }
            }
        }
        else
            printf("Entradas invalidas!");
    }
    else
    {
        if (*d <= 365 && *d >= 1 && *a >= 1)
        {
            for (int i = 0; i < sizeof(meses) / sizeof(meses[0]); i++)
            {
                if (*d > meses[i])
                {
                    mes++;
                    *d -= meses[i];
                }
                else
                {
                    dia = *d;
                    break;
                }
            }
        }
        else
            printf("Entradas invalidas!");
    }
            printf("%02d/%02d/%d\n", dia, mes, *a);
}
int main()
{
    int dia = 0, mes = 1;
    int ano = 0;

    scanf("%d %d", &dia, &ano);
    calculaDiaMes(&dia, &mes, &ano);

    return 0;
}
