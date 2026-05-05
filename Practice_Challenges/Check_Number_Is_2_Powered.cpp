//Program to check if a number of 2 powered

#include<iostream>
using namespace std;


int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    // if(((n>>1)%2) != 0)
    // cout<<"Not 2 powered"<<endl;
    // else
    // cout<<"Number is 2 powered"<<endl;

    // A number is a power of 2 if it's greater than 0 AND (n & (n - 1)) is 0
    if (n > 0 && (n & (n - 1)) == 0) {
        cout << n << " is 2 powered" << endl;
    } else {
        cout << n << " is NOT 2 powered" << endl;
    }
}