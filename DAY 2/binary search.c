#include <stdio.h>

int binarySearch(int array[], int length, int target) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        }

        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 30;

    int result = binarySearch(array, length, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

