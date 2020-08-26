/*
    https://www.acmicpc.net/problem/2156

    *생각
        두 가지 배열이 필요함.
        1. 각 포도주의 양을 담을 배열 (변경 x)
        2. 현재 까지 포도주 최대 누적량 기록 배열
    
    *풀이
        현재 n에서 최대 양을 구하는 경우를 나눠보자.
        1. n번째 포도주를 마시는 경우
            1. n-1번째 포도주를 마실 수 있으나 n-2는 못 마심
                * d[n][1] = d[n][0] + d[n-1][0] + d[n-3][1];
            2. n-1번째 포도주를 마시지 않고 n-2번째 포도주를 마심
                * d[n][1] = d[n][0] + d[n-2][1];
        2. n번째 포도주를 마시지 않는 경우
            1. n-1째 포도주의 최대 누적값과 같다.    
                * d[n][1] = d[n-1][1];
        
        - 이 3가지 경우 중 가장 큰(max) 값을 n누적배열에 기록한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long d[10001][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i=1; i<=num; i++){
        cin >> d[i][0];
    }
    d[1][1] = d[1][0] + d[0][0];
    d[2][1] = d[2][0] + d[1][0];
    for(int i=3; i<=num; i++){
        d[i][1] =max( d[i-1][1], d[i][0] + max( d[i-1][0] + d[i-3][1], d[i-2][1]) ); 
        //cout << i << " " << d[i][1] << "\n";
    }
    cout << d[num][1] << "\n";
}