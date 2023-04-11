//comparing elements to right side if greater present then printing that number else printing -1
//lab-9 qs-1

#include <stdio.h>

int main() {
    int no;
    scanf("%d", &no);

    int arr[no];
    printf("Enter elem:");
    for (int i = 0; i < no; i++) {
        scanf("%d", &arr[i]);
    }

    int greatest[no];
    for (int i = 0; i < no; i++) {
        greatest[i] = -1;
        for (int j = i+1; j < no; j++) {
            if (arr[j] > arr[i]) {
                greatest[i] = arr[j];
                break;
            }
        }
    }

    printf("Next greater elements in the array:\n");
    for (int i = 0; i < no; i++)
    {
        printf("%d -> %d\n", arr[i],greatest[i]);
    }

    return 0;
}


 

