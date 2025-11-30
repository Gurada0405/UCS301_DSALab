#include<iostream>
using namespace std;

int main()
{
    char str1[50], str2[40];

    cout<<"Enter first string:";
    cin.getline(str1, 50);
    cout<<"Enter second string:";
    cin.getline(str2, 40);


int i=0, j=0;

while (str1[i] != 0)

{
    i++;
}

while(str2[j] != 0)
{
    str1[i] = str2[j];
    i++;
    j++;
}

str1[i] = 0;

cout<<"Concatenated string is:"<<str1<<endl;

}