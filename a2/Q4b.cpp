#include<iostream>
using namespace std;

int main()
{
    char str[20];

    cout<<"Enter a string:";
    cin.getline(str, 20);

    int i, j, n;

    n=0;

    while(str[n] != 0)
    {
        n++;
    }

    for(int i=0, j=n-1; i<=j; i++, j--)
    {
        int temp = str[i];
            str[i]=str[j];
            str[j]=temp;
    }

    cout<<"Reversed string is:"<<str<<endl;

}