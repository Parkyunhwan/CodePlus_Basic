#include <iostream>
using namespace std;
#define MAX 100
int pri_n=0;
bool prime(int n)
{
    if(n < 2)
        return false;
    
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
            return false;
    }
    pri_n++;
    return true;
}

bool prime1(int n)
{
    if(n < 2)
        return false;
    
    for(int i=2; i<n/2; i++)
    {
        if(n%i==0)
            return false;
    }
    pri_n++;
    return true;
}

bool prime2(int n)
{
    if(n < 2)
        return false;
    
    for(int i=2; i*i<n; i++)
    {
        if(n%i==0)
            return false;
    }
    pri_n++;
    return true;
}

int main()
{
    int num;
    int arr[MAX];
    cin >> num;
    for(int i=0; i < num; i++)
        cin >> arr[i];
    for(int i=0; i < num; i++)
        prime(arr[i]);
    cout << pri_n;
}