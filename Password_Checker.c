#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_PASS_LEN 32
char password[MAX_PASS_LEN + 1];

void setPassword();
void checkPassword(char password[]);

int main() {
    int choice;
    while(1){
        printf("\n----------- MENU -----------\n");
        printf("1. Set password\n");
        printf("2. Check Password\n");
        printf("3. Change password\n");
        printf("4. Exit\n");
        printf("\nWhat's your choice : ");
        scanf("%d", &choice);
        getchar();
        printf("\n");

        if(choice == 1){
            setPassword();
        } else if(choice == 2) {
            if(strlen(password) == 0) {
                printf("No password is set yet.\n");
            } else {
                checkPassword(password);
            }
        } else if(choice == 3) {
            if(strlen(password) == 0) {
                printf("No password is set yet.\n");
            } else {
                setPassword();
            }
        } else if(choice == 4) {
            printf("------- Thank You! -------\n");
            break;
        } else {
            printf("Enter a valid number(i.e., 1,2,3,4) : ");
        }
    }
    return 0;
}

void setPassword() {
    printf("Enter your password : ");
    fgets(password, MAX_PASS_LEN + 1, stdin);

    password[strcspn(password, "\n")] = '\0';
    printf("\n");
    
    int len = strlen(password);
    if(len > 32) {
        printf("Password is too long.\n");
    } else if(len < 6) {
        printf("Enter a longer password.\n");
    } else {
        if(len < 8) {
            printf("Password is too short.\n");
        } else if(len >= 8 && len <= 12){
            printf("Password length is moderate.\n");
        } else if(len > 12 ){
            printf("Password is long.\n\n");
            char response;
            printf("Do you want to check it? (Y/N) : ");
            scanf(" %c", &response);
            response = toupper(response);
            if(response == 'Y') {
                checkPassword(password);
            } else{
                printf("Returning to main menu.\n");
                return;
            }
        }
    }
}

void checkPassword(char password[]) {
    int length = strlen(password);
    int hasUpper = 0;
    int hasLower = 0;
    int hasSpecial = 0;
    int hasDigit = 0;

    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }
    printf("\n");

    if(hasUpper && hasLower && hasDigit && hasSpecial) {
        printf("Password strength is strong.\n");
    } else{    
        if((hasUpper + hasLower + hasSpecial + hasDigit) >= 3) {
            printf("Password strength is medium.\n");
        } else {
            printf("Password strength is weak.\n");
        }
        printf("Missing requirements : \n");
        if(hasUpper == 0) {
            printf("- Uppercase letter\n");
        } if(hasLower == 0) {
            printf("- Lowercase letter\n");
        } if(hasDigit == 0) {
            printf("- Digit\n");
        } if(hasSpecial == 0) {
            printf("- Special character\n");
        }
    }

    char Response;
    printf("\nDo you want to change the password? (Y/N) : ");
    scanf(" %c", &Response);

    Response = toupper(Response);
    printf("\n");

    if(Response == 'Y'){
        printf("NOTE: This time try to complete the requirements to get a strong password.\n");
        setPassword();
    } else {
        printf("Returning to main menu.\n");
        return;
    }
}