#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int n) 
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == n) 
        {
            return mid;
        }

        else if (arr[mid] < n) 
        {
            left = mid + 1;
        }

        else 
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 89};
    int size = 10;
    int n = 23;
    
    int result = binarySearch(arr, size, n);

    if (result != -1) 
    {
        cout << "Element found at index: " << result << endl;
    } 

    else 
    {
        cout << "Element not found." << endl;
    }
    
    return 0;
} 