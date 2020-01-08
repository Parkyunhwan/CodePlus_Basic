#include <iostream>

using namespace std;
const int E_M = 15;
const int S_M = 28;
const int M_M = 19;

int main()
{
    int E,S,M;
    int e=1,s=1,m=1;
    int year = 1;
    cin >> E >> S >> M;
    while(1)
    {
        if(e==E && s==S && m==M)
            break;
        e++;
        s++;
        m++;
        year++;
        if(e > E_M)
            e = 1;
        if(s > S_M)
            s = 1;
        if(m > M_M)
            m = 1;
    }
    cout << year << endl;
}