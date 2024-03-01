/*MWANZIA SAMUEL
ENE212-0225/2019*/
#include <stdio.h>
/*Function to print the array*/ 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/*Function to remove Element to the array*/ 
void removeElement(int arr[], int size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}
/* Function to add Element to the array*/
void addElement(int arr[], int size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] > element) {
            break;
        }
    }
    if (i == size) {
        arr[i] = element;
    } else {
        for (int j = size; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = element;
    }
}
/*Function to sort the array in ascending order*/ 
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/*Main function*/
int main() {
    int arr[10] = {0};
    int size = 0;
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        size++;
    }
    printf("The array in the ascending order is: ");
    sortArray(arr, size);
    printArray(arr, size);
    int indexToRemove;
    printf("Enter the index to be removed(From 0-9): ");
    scanf("%d", &indexToRemove);
    if (indexToRemove >= 0 && indexToRemove < size) {
        removeElement(arr, size, indexToRemove);
        size--;
        printf("\nThe array with the omitted element in ascending order is: ");
        sortArray(arr, size);
        printArray(arr, size);
        int elementToAdd;
        printf("Enter the number to be added: ");
        scanf("%d", &elementToAdd);
        addElement(arr, size, elementToAdd);
        size++;
        printf("\nThe array with the added element in ascending order is: ");
        sortArray(arr, size);
        printArray(arr, size);
    } else {
        printf("Invalid index\n");
    }
    return 0;
}
