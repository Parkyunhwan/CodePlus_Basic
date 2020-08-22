/*
    https://www.acmicpc.net/problem/11727

    생각 
    규칙성을 찾으려고 노력중이다.
*/
#include <iostream>

using namespace std;
int d[1001];
int main()
{
    int n;
    cin >> n;
    d[1]=1;
    d[2]=3;
    for(int i=3; i <= n; i++){
        if(i%2==0){
            d[i]=d[i-1];
        }
        else{
            d[i]=(d[i-2]*3)%10700;
        }
        
    }
    cout << d[n] << "\n";
}