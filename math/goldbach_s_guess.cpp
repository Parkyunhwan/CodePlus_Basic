#include <iostream>
using namespace std;
#define MAX 100000
int num[MAX];
bool prin[MAX]={false,};
int n1,n2;
bool prime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i < n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void check(int n)
{
    for(int i=0; i < n; i++)
    {
        bool c;
        c=prime(i);
        if(c)
            prin[i]=true;
        else
        {
            prin[i]=false;
        }
        
    }
}

void goldbach(int n)
{
    check(n);
    for(int i=n; i >= 2; i--)
    {
        if(prin[i]==true)
            n1 = prin[i];
        else
            continue;
        for(int j=i; i >=2; j--)
        {
            if(prin[j]==true)
                n2 = prin[j];
            else
                continue;
            if(n == (n1+n2))
                break;
        }
        if(n == (n1+n2))
            break;
        
    }
    cout << n << "=" << n1 << "+" << n2 << endl;
}
int main()
{
    int i=0;
    while(1)
    {
        cin >> num[i];
        if(num[i]==0)
            break;
        i++;
    }
    i=0;
    while(1)
    {
        if(num[i]==0)
            break;
        goldbach(num[i]);
        i++;
    }
}