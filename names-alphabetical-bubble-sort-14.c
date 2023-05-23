//names in alphabetical order 
//using bubble sort
#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

void bubbleSort(char names[][MAX_LENGTH], int size) {
    int i, j;
    char temp[MAX_LENGTH];

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int i, n;
    char names[MAX_NAMES][MAX_LENGTH];

    printf("Enter the no of names: ");
    scanf("%d", &n);

    printf("Enter the names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    bubbleSort(names, n);

    printf("\nSorted names:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
