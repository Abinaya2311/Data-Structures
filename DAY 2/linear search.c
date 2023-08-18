#include <stdio.h>

int linearSearch(int array[], int length, int target) {
	int i;
    for (i = 0; i < length; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 30;

    int result = linearSearch(array, length, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

