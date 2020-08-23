/*
    https://www.acmicpc.net/problem/16194

    생각
        카드 구매하기 1번과 같은 문제..
        다만, 최솟값을 구해야 했다.
        max 대신 min을 사용했고 min을 사용하기위해 첫 삽입 시에만 무조건 값을 넣어주도록 했다.

        나머지 구현은 1번과 동일하다.
*/
#include <iostream>
#include <climits>
#include <algorithm>
#include <memory.h>
using namespace std;
int N;
int d[1001];
int p[1001];
int minimum = INT_MAX;
int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> p[i];
    d[0]=0;
    for(int j=1; j <= N; j++){
        for(int i = 0; i < j; i++){
            int k = d[i] + p[j-i];
            if(d[j]==0)
                d[j] = k;
            else
                d[j] = min(d[j], k);
        }
    }
    cout << d[N] << "\n";
}