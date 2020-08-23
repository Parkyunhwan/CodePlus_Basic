/*
    https://www.acmicpc.net/problem/11052

    생각
        한 가지 값을 잡고(ex> 4) 어떻게 하면 최댓값을 기억하며 구할 수 있을지 고민했다.
        1의최대(d[1])   2의최대(d[2])   3의최대(d[3])   4의최대(d[4])
        +   p[1]        +   p[2]        + p[3]          +   p[4]
        =   max( d[4] )
        이를 통해 최댓값을 기억하며 구할 수 있었다.

    풀이
        1. 1일때 최댓값을 구해 d[1] 대입
        2. 이전의 값을 이용해 현재 최댓값을 구함
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1001];
int d[1001];
int main()
{
    cin >> N;
    int k;
    for(int i=1; i <= N; i++)
        cin >> p[i];
    d[0]=0;
    d[1]=1;
    for(int j=1; j<=N; j++){
        for(int i=0; i < j; i++){
            int k = d[i]+p[j-i];
            d[j] = max(d[j],k);
        }
    }
    cout << d[N] << "\n";
}