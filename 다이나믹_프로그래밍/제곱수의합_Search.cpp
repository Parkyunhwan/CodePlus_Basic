/*
    https://www.acmicpc.net/problem/1699
    [Search]
    생각
        ** dp는 어떻게 하면 값을 기록해가며 문제를 해결할 수 있을지 고민 해야한다.
        * 이 문제는 해당 숫자에 대해 제곱수를 빼가면서 최솟값을 기록해야 했다.
        * 숫자가 커지면서 이전 최솟값을 이용해서 해당 최솟값을 구하게 된다.
        
*/
#include <iostream>
#include <algorithm>
using namespace std;
int d[100001];
int main()
{
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        d[i] = i;
        for(int j=1; j*j <= i; j++){
            d[i] = min(d[i],d[i-j*j]+1);
            
        }
    }
    cout << d[n] << "\n";
}