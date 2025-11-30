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

bool checkBalancedParentheses(char expr[]) 
{
    Stack s;
    int i = 0;
    
    while (expr[i] != '\0') 
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') 
        {
            s.push(expr[i]);
        }

        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') 
        {
            if (s.isEmpty()) return false;
            
            char top = s.pop();
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) 
            {
                return false;
            }
        }

        i++;
    }

    return s.isEmpty();
}

int main() 
{
    char expr[100];
    
    cout << "Enter an expression to check balanced parentheses: ";
    cin >> expr;
    
    if (checkBalancedParentheses(expr)) 
    {
        cout << "Parentheses are BALANCED" << endl;
    } 
    
    else 
    {
        cout << "Parentheses are NOT BALANCED" << endl;
    }
    
    return 0;
}