#include <stdio.h>

int main(){
    FILE *record;
    struct employee{
        char name [20];
        int age;
        float salary;
    }; struct employee e1;
    record = fopen("employee_records.DAT", "r");
    if (record == NULL){
        printf("Unable to open the file");
        return 0;
    }
    while (fscanf(record, "%[^,],%d,%f\n", e1.name, &e1.age, &e1.salary) == 3)
    printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", e1.name, e1.age, e1.salary);

    fclose(record);
    return 0;
}