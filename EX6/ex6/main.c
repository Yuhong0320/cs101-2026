#include <stdio.h>
#include <string.h>

#define NAME_LEN 10
#define MAX_EMP 10
#define FILE_NAME "employee.bin"

typedef struct employee {
    int id;
    char name[NAME_LEN];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp);
int emp_aveage_age(employee_t emp[], int n);
void emp_writefile(employee_t emp[], int n);
int emp_readfile(employee_t emp[], int max);

void emp_info(employee_t emp)
{
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %.2f\n\n", emp.salary);
}

int emp_aveage_age(employee_t emp[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

void emp_writefile(employee_t emp[], int n)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    fclose(fp);
}

int emp_readfile(employee_t emp[], int max)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        return 0;
    }
    int count = 0;
    while (count < max && fread(&emp[count], sizeof(employee_t), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}

int main(void)
{
    employee_t emp[3];
    employee_t read_emp[MAX_EMP];

    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0f;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0f;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0f;
    strcpy(emp[2].name, "swift");

    printf("Average age: %d\n\n", emp_aveage_age(emp, 3));

    emp_writefile(emp, 3);

    int n = emp_readfile(read_emp, MAX_EMP);
    for (int i = 0; i < n; i++) {
        emp_info(read_emp[i]);
    }
    return 0;
}