/*Write a program that contains a structure named Employee which contains the following
data members:
● employeeCode
● employeeName
● dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 3 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of
each employee, and checks if the tenure is more than three years. Display the details of
arr with tenure of more than three years and the count of such arr.*/

#include <stdio.h>
#include <string.h>
#define X 3

typedef struct {
    int employeeCode;
    char employeeName[25];
    int dateOfJoining; 
} Employee;
void func();
void tenure();
void func(Employee arr[], int X) {
    for (int i = 0; i < X; i++) {
        printf("Employee Code: ");
        scanf("%d", &arr[i].employeeCode);

        printf("Employee Name: ");
        scanf("%s", arr[i].employeeName);

        printf("Date of Joining : ");
        scanf("%d", &arr[i].dateOfJoining);
    }
}

void tenure(Employee arr[], int X) {
    int currentDate, count = 0;
    printf("\nEnter the current date : ");
    scanf("%d", &currentDate);

    for (int i = 0; i < X; i++) {
        int yearJoined = arr[i].dateOfJoining / 10000;
        int currentYear = currentDate / 10000;
        int tenure = currentYear - yearJoined;

        if (tenure > X) {
            count++;
            printf("%d\t%s\t\t%d\t\t%d\n",
                   arr[i].employeeCode,
                   arr[i].employeeName,
                   arr[i].dateOfJoining,
                   tenure);
        }
    }
    printf("Total number of arr with tenure > 3 years: %d\n", count);
}

int main() {
    Employee arr[X];

    func(arr, X);
    tenure(arr, X);

    return 0;
}
