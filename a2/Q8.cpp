#include <iostream>
using namespace std;


int countDistinct(int arr[], int size) 
{
    int distinctCount = 0;
    
    for (int i = 0; i < size; i++) 
    {
       
        bool isDistinct = true;

        for (int j = 0; j < i; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) 
        {
            distinctCount++;
        }
    }
    
    return distinctCount;
}

void displayArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = 6;

    cout << "Array 1: ";
    displayArray(arr, size);
    cout << "Distinct elements: " << countDistinct(arr, size) << endl;
}
