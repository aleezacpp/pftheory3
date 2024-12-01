/*Create a program to validate an email address based on a few basic criteria. The program will
prompt the user to enter an email address and will dynamically allocate memory to store and
process the input.
Define the following function:
1. int validateEmail(char* email): This function validates the email based on the following
criteria:
○ Contains exactly one @ symbol.
○ Contains at least one dot (.) after the @ symbol.
○ Is non-empty.
○ Returns 1 if the email is valid, and 0 if invalid.
Steps:
1. User Input: Prompt the user to enter an email address. Allocate memory dynamically for
the email, ensuring the memory size is based on the input length.
2. Validation Process:
○ Call the validateEmail function to check if the email meets the criteria.
3. Display Results:
○ Print "Valid Email" if the email meets the criteria.
○ Print "Invalid Email" if the email does not meet the criteria.
4. Memory Cleanup:
○ Free the dynamically allocated memory after validation to prevent memory leaks.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT 10
int validateemail(char* email){
    int flag=0;
    int flag2=0;
    char x='@';
    char x2='.';
    int pos1=-1;
    int pos2=-1;
    for (int i=0;email[i]!='\0';i++){
        if (email[i]==x){
            flag++;
            pos1=i;
            //pos of @ recorded
        }
        if (email[i]==x2){
            pos2=i;
            if (pos2>pos1 && pos1!=-1){
                flag2++;
            }
        }
        
    }
    if (flag!=1 || flag2<1){
        printf("INVALID EMAIL\n");
        return 0;
    }
    else {
    printf("VALID EMAIL\n");
    return 1;
    }
}
int main(){
    char *email = (char *)malloc(INT*sizeof(char));
    if (email==NULL){
        printf("ALLOCATION FAILED\n");
        return 1;
    }
    printf("enter email : \n");
    scanf("%s",email);

    
    if (strlen(email)>(INT-1)){
        email=(char *)realloc(email,(strlen(email)+1)*sizeof(char));
        if (email==NULL){
            printf("INVALID ALLOCATION\n");
            return 1;
        }
    }
    validateemail(email);
    free(email);
    return 0;

}