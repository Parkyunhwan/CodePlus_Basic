/*
    *맞추지 못한 문제*
    dp 문제로 bfs를 통해서는 메모리 초과를 겪게 된다.
    규칙성을 찾는 것이 가장 중요했다.

    n번째 갯수는 
    n-1번째에 세로방향의 직사각형이 붙은 것이고
    n-2번째에 가로방향의 직사각형2개가 붙은 것이다.

    이 규칙성을 찾는 것이 중요했다.
    dp문제에서 피보나치 변형은 자주 사용된다.
*/

#include <iostream>
using namespace std;
int d[1001];
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    d[1]=1;
    d[2]=2;
    for(int i=3; i<=n;i++)
    {
        d[i]=(d[i-1]+d[i-2])%10007;
    }
    cout << d[n] << "\n";
}