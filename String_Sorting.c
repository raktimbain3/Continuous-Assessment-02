#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char str[]);
void sortAlphabetically(char arr[][100], int n);
void sortByLength(char arr[][100], int n);
int main() 
{
    int n;
    char str[10][100];
    char upperStr[10][100];
    char choice;

    do {
        printf("\nEnter number of strings (1-10): ");
        scanf("%d", &n);
        getchar();  // To consume leftover newline

        for (int i = 0; i < n; i++) {
            printf("Enter string %d: ", i + 1);
            fgets(str[i], sizeof(str[i]), stdin);
            str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline
            strcpy(upperStr[i], str[i]);
            toUpperCase(upperStr[i]);
        }

        printf("\nOriginal strings: ");
        for (int i = 0; i < n; i++) {
            printf("%s", str[i]);
            if (i < n - 1) printf(", ");
        }
        printf("\n");

        printf("Uppercase strings: ");
        for (int i = 0; i < n; i++) {
            printf("%s", upperStr[i]);
            if (i < n - 1) printf(", ");
        }
        printf("\n");

        printf("Lengths: ");
        for (int i = 0; i < n; i++) {
            printf("%lu", strlen(upperStr[i]));
            if (i < n - 1) printf(", ");
        }
        printf("\n");

        sortAlphabetically(upperStr, n);
        printf("Sorted alphabetically: ");
        for (int i = 0; i < n; i++) {
            printf("%s", upperStr[i]);
            if (i < n - 1) {printf(", ");}
        }
        printf("\n");

        sortByLength(upperStr, n);
        printf("Sorted by length: ");
        for (int i = 0; i < n; i++) {
            printf("%s", upperStr[i]);
            if (i < n - 1) {printf(", ");}
        }
        printf("\n");

        printf("Sort again? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume leftover newline

    } while (choice == 'y' || choice == 'Y');

    printf("Program ended.\n");

    return 0;
}
void toUpperCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}
void sortAlphabetically(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) 
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
void sortByLength(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strlen(arr[i]) > strlen(arr[j])) 
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}