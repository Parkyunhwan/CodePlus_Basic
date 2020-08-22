/*
    https://www.acmicpc.net/problem/11727

    생각 
    규칙성을 찾는 것이 중요한 문제였다.
    규칙성을 찾기 위해선 순서대로 그려보는 게 가장 직관적으로 해답을 구할수 있었다.
    
    풀이
    현재 타일(n)을 모두 채우는 방법은 
    1. n-2 타일의 모든 방법에 (=,||,☐) 세가지를 추가한 방법의수
       -> d[n-2] x 3
    2. n-1 타일의 모든 방법에 ( | )을 추가하는 방법의 수
       -> d[n-1] x 1
    3. 1에서 n-2타일의 |로 끝나는 타일들은 2와 겹치는 타일이 존재한다.
    4. 따라서 n-2에서 ||은 제외하고 =,☐ 두가지 추가한 방법의 수만 구한다.
       -> d[n-2] x 2
    
    따라서, 답은 d[n-2]*2 + d[n-1] d이다. (10007은 오버플로우 방지)
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
    for(int i=3; i <= n; i++)
            d[i]= (d[i-2]*2+d[i-1])%10007;
    cout << d[n] << "\n";
}