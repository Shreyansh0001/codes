#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=1,b=1,c;
    cout<<a<<"\t"<<b <<"\t";
    while(n>2)
    {
        c = a+b;
        a=b;
        b=c;
        cout<<c<<"\t";
        n--;
    }
    return 0;
}