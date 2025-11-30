#include<iostream>
using namespace std;

int main()
{
    char str[20];

    cout<<"Enter a string:";
    cin.getline(str, 20);

    int i, pos, n;

    n=0;
    while(str[n] != 0)
    {
        n++;
    }

    for (int i=0; i<n; i++)
    {
       if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || 
        str[i]=='A'|| str[i]=='E' || str[i]=='I' || str[i]=='O'|| str[i]=='U')
        {
            for(int j=i; j<n-1; j++)
            {
                str[j] = str[j+1];
            }

            n--;
            i--;
        }
       
    }

    str[n] = '\0';
    
    cout<<"New string after deleting vowels is:"<<str<<endl;

}