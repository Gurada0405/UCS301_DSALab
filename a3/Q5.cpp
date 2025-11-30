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
        if (top >= MAX - 1) 
        {
            return false;
        }

        arr[++top] = value;
        return true;
    }

    int pop() 
    {
        if (top < 0) 
        {
            return -1;
        }

        return arr[top--];
    }

    bool isEmpty() 
    {
        return top == -1;
    }
};

bool isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int evaluatePostfix(char postfix[]) 
{
    Stack s;
    int i = 0;
    
    while (postfix[i] != '\0') 
    {
        char ch = postfix[i];
        
        // If operand, push to stack
        if (ch >= '0' && ch <= '9') 
        {
            s.push(ch - '0'); // Convert char to int
        }
        // If operator, pop two operands, perform operation and push result
        else if (isOperator(ch)) 
        {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;
            
            switch(ch) 
            {
                case '+': 
                    result = val1 + val2; 
                    break;
                case '-': 
                    result = val1 - val2; 
                    break;
                case '*': 
                    result = val1 * val2; 
                    break;
                case '/': 
                    result = val1 / val2; 
                    break;
                case '^': 
                    result = 1;
                    for (int k = 0; k < val2; k++) 
                        result *= val1;
                    break;
                default:
                    result = 0;
            }

            s.push(result);
        }

        i++;
    }

    return s.pop();
}

int main() 
{
    char postfix[100];
    
    cout << "Enter postfix expression (use single-digit numbers only): ";
    cin >> postfix;
    
    int result = evaluatePostfix(postfix);
    
    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << result << endl;
    
    return 0;
}