#include <iostream>
using namespace std;

#define MAX 100

class Stack 
{
    
    private:
    char arr[MAX];
    int top;
    
    public:
    Stack() 
    {
        top = -1;
    }

    bool push(char value) 
    {
        if (top >= MAX - 1) 
        {
            return false;
        }
        arr[++top] = value;
        return true;
    }

    char pop() 
    {
        if (top < 0) 
        {
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() 
    {
        return top == -1;
    }
};

void reverseString(char str[]) 
{
    Stack s;
    int i = 0;
    
    // Push all characters to stack
    while (str[i] != '\0') 
    
    {
        s.push(str[i]);
        i++;
    }
    
    // Pop characters to reverse string
    i = 0;
    while (!s.isEmpty()) 
    
    {
        str[i++] = s.pop();
    }
}

int main() 
{
    char str[100];
    
    cout << "Enter a string to reverse: ";
    cin >> str;
    
    cout << "Original string: " << str << endl;
    
    reverseString(str);
    
    cout << "Reversed string: " << str << endl;
    
    return 0;
}