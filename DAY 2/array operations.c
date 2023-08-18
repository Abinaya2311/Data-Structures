#include <stdio.h>

// Function to display the contents of the array
void displayArray(int array[], int length) {
	int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int maxArraySize = 20;
    int array[maxArraySize];
    int length = 0, i;

    // Input the elements of the array
    printf("Enter the number of elements (up to %d): ", maxArraySize);
    scanf("%d", &length);

    if (length > maxArraySize) {
        printf("Maximum array size exceeded.\n");
        return 1; // Exit with an error code
    }

    printf("Enter %d elements: ", length);
    for (i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    // Insertion
    int position;
    int newValue;

    printf("Enter the position for insertion: ");
    scanf("%d", &position);

    printf("Enter the new value for insertion: ");
    scanf("%d", &newValue);

    if (position >= 0 && position <= length) {
        for (i = length; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = newValue;
        length++;
    }

    printf("After Insertion: ");
    displayArray(array, length);

    // Search
    int target;
    int foundIndex = -1;

    printf("Enter the target element for search: ");
    scanf("%d", &target);

    for (i = 0; i < length; i++) {
        if (array[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Element found at index %d\n", foundIndex);
    } else {
        printf("Element not found\n");
    }

    // Update
    int indexToUpdate;
    int updatedValue;

    printf("Enter the index to update: ");
    scanf("%d", &indexToUpdate);

    if (indexToUpdate >= 0 && indexToUpdate < length) {
        printf("Enter the new value for update: ");
        scanf("%d", &updatedValue);
        array[indexToUpdate] = updatedValue;
    }

    printf("After Update: ");
    displayArray(array, length);

    // Deletion
    int indexToDelete;

    printf("Enter the index for deletion: ");
    scanf("%d", &indexToDelete);

    if (indexToDelete >= 0 && indexToDelete < length) {
        for (i = indexToDelete; i < length - 1; i++) {
            array[i] = array[i + 1];
        }
        length--;
    }

    printf("After Deletion: ");
    displayArray(array, length);

    return 0;
}
