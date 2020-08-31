/*
    https://www.acmicpc.net/problem/1912

    생각
        전형적인 dp
        현재 값이 최선이라면 이전 값을 신경쓰지 않아도 되는 문제이다.
        현재 값으로 부터 최고값을 갱신해 나간다.
    풀이
        * 숫자를 더해 나간다.
        * 누적값과 현재 값을 비교 해서 큰 값을 선택한다.
        * 현재 최고값보다 값이 크다면 최고값을 갱신한다.
*/

#include <iostream>
#include <algorithm>

using namespace std;
int dp[100001];
int arr[100001];
int main()
{
    int n,ans;
    cin >> n;

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    ans = dp[1] = arr[1];

    for(int i=2; i<=n; i++){
        dp[i] = max(arr[i],dp[i-1]+arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";    
}

