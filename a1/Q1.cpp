#include <iostream>
using namespace std;

int main()
{
    int n = 0;  
    int A[50];  
    int m;      

    do 
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Create Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Linear Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> m;

        switch (m) 
        {
        case 1:      // Create array
        { 
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) 
            {
                cin >> A[i];
            }
            break;
        }

        case 2:       // Display array
        { 
            if (n == 0) {
                cout << "Array is empty!\n";
            } else {
                cout << "Array elements: ";
                for (int i = 0; i < n; i++) {
                    cout << A[i] << " ";
                }
                cout << endl;
            }
            break;
        }

        case 3:      // Insert element
        { 
            int ele, pos;
            cout << "Enter element to be inserted: ";
            cin >> ele;
            cout << "Enter position (0-based index): ";
            cin >> pos;

            if (pos < 0 || pos > n)
            {
                cout << "Invalid position!\n";
            } 
            else 
            {
                for (int i = n; i > pos; i--) 
                {
                    A[i] = A[i - 1];
                }
                A[pos] = ele;
                n++; 
                cout << "Element inserted.\n";
            }
            break;
        }

        case 4:          // Delete element 
        { 
            int pos;
            cout << "Enter position (0-based index): ";
            cin >> pos;

            if (pos < 0 || pos >= n) 
            {
                cout << "Invalid position!\n";
            } 
            else
            {
                for (int i = pos; i < n - 1; i++) 
                {
                    A[i] = A[i + 1];
                }
                n--; 
                cout << "Element deleted.\n";
            }
            break;
        }

        case 5:     // Linear search
        { 
            int ele;
            cout << "Enter element to search: ";
            cin >> ele;
            int f = 0;
            for (int i = 0; i < n; i++) 
            {
                if (A[i] == ele) 
                {
                    cout << "Element found at index " << i << endl;
                    f = 1;
                    break;
                }
            }
            if (!f)
                cout << "Element not found!\n";
            break;
        }

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } 
    
    while (m != 6);

    return 0;
}
