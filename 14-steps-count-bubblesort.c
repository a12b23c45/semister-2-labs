//steps comaprison in bubble sort to occur
#include <stdio.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size, int* comp) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            (*comp)++;
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int size;
    printf("Enter the no of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int comp_sorted = 0;

    printf("\nAfter sorting:\n");
    printArray(arr, size);

    int sortedArr[size];
    for (int i = 0; i < size; i++) 
    {
        sortedArr[i] = arr[i];
    }

    bubbleSort(sortedArr, size, &comp_sorted);
    printf("No of comparisons: %d\n", comp_sorted);

    return 0;
}
