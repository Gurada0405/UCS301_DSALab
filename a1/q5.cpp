
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of matrix";
    cin>>n;
    int A[n][n]; int C[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter element";
            cin>>A[i][j];
    }
    }
   
   
    for(int i=0;i<n;i++)
    {  int r=0;
        for (int j=0;j<n;j++)
        {
            r=r+A[i][j];
           
        }
        cout<<"Sum of "<<i+1<<" Row ="<<r<<"\n";
    }
    for(int i=0;i<n;i++)
    { int c=0;
        for(int j=0;j<n;j++)
        {
            c=c+A[j][i];
        }
        cout<<"Sum of "<<i+1<<" Column="<< c<<"\n";
    }
    return 0;


}
