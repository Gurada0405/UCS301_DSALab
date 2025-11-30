#include <iostream>
using namespace std;

#define MAX 100

class Stack 
{
    private:
    int arr[MAX];
    int top;
    
    public:
    Stack() 
    {
        top = -1;
    }

    bool push(int value) 
    {
        if (isFull()) 
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return false;
        }

        arr[++top] = value;
        cout << value << " pushed to stack\n";
        return true;
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow! Cannot pop\n";
            return -1;
        }

        return arr[top--];
    }

    bool isEmpty() 
    {
        return top == -1;
    }

    bool isFull() 
    {
        return top == MAX - 1;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";

        for (int i = top; i >= 0; i--) 
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[top];
    }
};

int main() 
{
    Stack s;
    int choice, value;
    
    do 
    {
        cout << "\n===== STACK OPERATIONS =====" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Check if stack is empty" << endl;
        cout << "4. Check if stack is full" << endl;
        cout << "5. Display stack" << endl;
        cout << "6. Peek top element" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
                
            case 2:
                value = s.pop();

                if (value != -1) 
                {
                    cout << "Popped value: " << value << endl;
                }
                break;
                
            case 3:

                if (s.isEmpty()) 
                {
                    cout << "Stack is empty" << endl;
                } 

                else 
                {
                    cout << "Stack is not empty" << endl;
                }
                break;
                
            case 4:

                if (s.isFull()) 
                {
                    cout << "Stack is full" << endl;
                } 

                else 
                {
                    cout << "Stack is not full" << endl;
                }
                break;
                
            case 5:
                s.display();
                break;
                
            case 6:

                value = s.peek();

                if (value != -1)
                {
                    cout << "Top element: " << value << endl;
                }

                break;
                
            case 7:

                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 
    
    while (choice != 7);
    
    return 0;
}