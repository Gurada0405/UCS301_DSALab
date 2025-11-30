#include <iostream>
using namespace std;

class SortingAlgorithms {
private:
    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int* leftArr = new int[n1];
        int* rightArr = new int[n2];
        
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
        
        delete[] leftArr;
        delete[] rightArr;
    }
    
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

public:
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[minIndex], arr[i]);
        }
    }
    
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    
    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            merge(arr, left, mid, right);
        }
    }
       void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    void improvedSelectionSort(int arr[], int n) {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int minIndex = i;
            int maxIndex = i;
            
            for (int k = i; k <= j; k++) {
                if (arr[k] < arr[minIndex]) {
                    minIndex = k;
                }
                if (arr[k] > arr[maxIndex]) {
                    maxIndex = k;
                }
            }
            
            swap(arr[i], arr[minIndex]);
            
            
            if (maxIndex == i) {
                maxIndex = minIndex;
            }
            
            swap(arr[j], arr[maxIndex]);
        }
    }
    
    void displayArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void copyArray(int source[], int dest[], int n) {
        for (int i = 0; i < n; i++) {
            dest[i] = source[i];
        }
    }
};

int main() {
    SortingAlgorithms sorter;
    int choice, n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* originalArr = new int[n];
    int* tempArr = new int[n];
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> originalArr[i];
    }
    
    do {
        cout << "\n--- Sorting Algorithms Menu ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Improved Selection Sort (Min-Max)\n";
        cout << "7. Display Original Array\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        sorter.copyArray(originalArr, tempArr, n);
        
        switch(choice) {
            case 1:
                cout << "Original array: ";
                sorter.displayArray(tempArr, n);
                sorter.selectionSort(tempArr, n);
                cout << "After Selection Sort: ";
                sorter.displayArray(tempArr, n);
                break;
                
            case 2:
                cout << "Original array: ";
                sorter.displayArray(tempArr, n);
                sorter.insertionSort(tempArr, n);
                cout << "After Insertion Sort: ";
                sorter.displayArray(tempArr, n);
                break;
                
            case 3:
                cout << "Original array: ";
                sorter.displayArray(tempArr, n);
                sorter.bubbleSort(tempArr, n);
                cout << "After Bubble Sort: ";
                sorter.displayArray(tempArr, n);
                break;
                
            case 4:
                cout << "Original array: ";
                sorter.displayArray(tempArr, n);
                sorter.mergeSort(tempArr, 0, n - 1);
                cout << "After Merge Sort: ";
                sorter.displayArray(tempArr, n);
                break;
                
            case 5:
                cout << "Original array: ";
                sorter.displayArray(tempArr, n);
                sorter.quickSort(tempArr, 0, n - 1);
                cout << "After Quick Sort: ";
                sorter.displayArray(tempArr, n);
                break;
                
            case 6:
                cout << "Original array: ";
                sorter.displayArray(tempArr, n);
                sorter.improvedSelectionSort(tempArr, n);
                cout << "After Improved Selection Sort: ";
                sorter.displayArray(tempArr, n);
                break;
                
            case 7:
                cout << "Original array: ";
                sorter.displayArray(originalArr, n);
                break;
                
            case 8:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    
    delete[] originalArr;
    delete[] tempArr;
    
    return 0;
}