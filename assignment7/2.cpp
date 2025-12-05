#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;          // start of array
    int right = n - 1;     // end of array

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If left element is greater than right, swap
        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        // Find min and max in remaining part
        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at left
        swap(arr[left], arr[minIndex]);

        // If max element was at left, update its index
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum at right
        swap(arr[right], arr[maxIndex]);

        // Move boundaries
        left++;
        right--;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90};
    int n = 6;

    cout << "Original Array: ";
    display(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}
