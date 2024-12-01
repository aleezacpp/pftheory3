#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    int *ratings;
    int totalscore;
} Employees;

void inputemployees(Employees *employees, int numemp, int period) {
    for (int i = 0; i < numemp; i++) {
        employees[i].ratings = (int *)malloc(period * sizeof(int));
        if (employees[i].ratings == NULL) {
            printf("Memory allocation failed for employee %d\n", i + 1);
            exit(1);
        }
        printf("Enter ratings for employee[%d] for %d evaluation periods:\n", i + 1, period);
        for (int j = 0; j < period; j++) {
            do {
                printf("Enter rating for period %d (1 to 10): ", j + 1);
                scanf("%d", &employees[i].ratings[j]);
            } while (employees[i].ratings[j] > 10 || employees[i].ratings[j] < 1);
        }
    }
}

void displayperf(int numemp, int period, Employees *employees) {
    for (int i = 0; i < numemp; i++) {
        printf("Employee %d Ratings: ", i + 1);
        for (int j = 0; j < period; j++) {
            printf("%d ", employees[i].ratings[j]);
        }
        printf("\n");
    }
}

int main() {
    int numemp, period;

    printf("Enter the number of employees: ");
    scanf("%d", &numemp);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &period);

    Employees *employees = (Employees *)malloc(numemp * sizeof(Employees));
    if (employees == NULL) {
        printf("Memory allocation failed for employees array.\n");
        return 1;
    }

    inputemployees(employees, numemp, period);
    printf("\nEmployee Performance Ratings:\n");
    displayperf(numemp, period, employees);

    // Free allocated memory
    for (int i = 0; i < numemp; i++) {
        free(employees[i].ratings);
    }
    free(employees);

    return 0;
}
