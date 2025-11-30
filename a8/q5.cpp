#include <iostream>
using namespace std;

class HeapSort {
private:
    void heapify(int arr[], int n, int i, bool increasing) {
        int extreme = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (increasing) {
            if (left < n && arr[left] > arr[extreme]) {
                extreme = left;
            }
            if (right < n && arr[right] > arr[extreme]) {
                extreme = right;
            }
        } else {
            if (left < n && arr[left] < arr[extreme]) {
                extreme = left;
            }
            if (right < n && arr[right] < arr[extreme]) {
                extreme = right;
            }
        }
        
        if (extreme != i) {
            swap(arr[i], arr[extreme]);
            heapify(arr, n, extreme, increasing);
        }
    }
    
public:
    void heapSort(int arr[], int n, bool increasing = true) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, increasing);
        }
        
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0, increasing);
        }
    }
    
    void displayArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    HeapSort sorter;
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Original array: ";
    sorter.displayArray(arr1, n);
    
    sorter.heapSort(arr1, n, true);
    cout << "Heap Sort (Increasing): ";
    sorter.displayArray(arr1, n);
    
    sorter.heapSort(arr2, n, false);
    cout << "Heap Sort (Decreasing): ";
    sorter.displayArray(arr2, n);
    
    return 0;
}