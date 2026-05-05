//Program to check if a number of 2 powered

#include<iostream>
using namespace std;


int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    if(((n>>1)%2) != 0)
    cout<<"Not 2 powered"<<endl;
    else
    cout<<"Number is 2 powered"<<endl;
}