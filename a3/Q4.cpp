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

    char peek() 
    {
        if (top < 0) 
        {
            return '\0';
        }

        return arr[top];
    }

    bool isEmpty() 
    {
        return top == -1;
    }
};

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char infix[], char postfix[]) 
{
    Stack s;
    int i = 0, j = 0;
    
    while (infix[i] != '\0') 
    {
        char ch = infix[i];
        
        // If operand, add to output
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) 
        {
            postfix[j++] = ch;
        }

        // If '(', push to stack
        else if (ch == '(') 
        {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') 
        {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop(); // Remove '('
            }
        }
        // If operator
        else if (isOperator(ch)) 
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
        i++;
    }
    
    // Pop remaining operators
    while (!s.isEmpty()) 
    {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';

}

int main() 
{
    char infix[100], postfix[100];
    
    cout << "Enter infix expression: ";
    cin >> infix;
    
    infixToPostfix(infix, postfix);
    
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}