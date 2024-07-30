#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
void clear();


int main(){
    FILE *record;
    char option = 'Y';
    struct employeer {
        char name[20];
        int age;
        float salary;
    };
    struct employeer e1;

    record = fopen("employee_records.DAT", "a");
    if (record == NULL){
        printf("Unable to open 'employee_records.DAT', creating a new one\n");
        record = fopen("employee_records.DAT", "w");
        if (record == NULL){
            printf("Unable to create new file\n");
            return 0;
        }
    }
    
    do {
        clrscr();
        printf("Name: ");
        scanf("%s", e1.name);
        printf("Age: ");
        scanf("%d", &e1.age);
        printf("Salary: ");
        scanf("%f", &e1.salary);
        fprintf(record, "%s, %d, %f\n", e1.name, e1.age, e1.salary);
        printf("\nDo you want to add more employe records? (Y/N)\n");
        clear();
        option = getchar();
    } while (option == 'Y' || option == 'y');
    clrscr();
    printf("\nThank you for using our employee recording system!\n");
    /*
    while (option == 'Y' || option == 'y'){
        printf("Name: ");
        scanf("%s", e1.name);
        printf("Age: ");
        scanf("%d", &e1.age);
        printf("Salary: ");
        scanf("%f", &e1.salary);
        fscanf(record, "Name: %s \nAge: %d\n Salary: %f\n", e1.name, &e1.age, &e1.salary);
        printf("\n\nDo you want to add more employe records? (Y/N)\n");
        clear();
        option = getchar();
    }
    */
    fclose (record);
    return 0;
}

void clear (void)
{
    while ( getchar() != '\n' );
}