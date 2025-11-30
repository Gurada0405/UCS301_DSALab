#include<iostream>
using namespace std;

int countInversionsBubbleSort(int arr[], int size) 
{
    int invCount = 0;
    int temp[size];
    
    for (int i = 0; i < size; i++) 
    {
        temp[i] = arr[i];
    }
    
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (temp[j] > temp[j + 1]) 
            {
                // Swap elements
                int swapTemp = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swapTemp;
                invCount++;
            }
        }
    }

return invCount;
}

void displayArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[] = {2, 4, 1, 6, 10};
    int size = 5;

    cout << "Array : ";
    displayArray(arr, size);
    cout << "Inversions (Bubble Sort): " << countInversionsBubbleSort(arr, size) << endl;
    cout << endl;
}