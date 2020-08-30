/*
	https://www.acmicpc.net/problem/13398
	[Search]
	생각
		* 어떻게 하면 수를 제거할 수 있을때 최댓값을 구할 수 있을까?
		* 먼저 두 가지 경우를 생각해야 한다.
		* 1. 수를 제거하지 않았을 때 최댓값
		* 2. 수를 제거했을 경우 최댓값
	
	풀이
		1. 수를 제거하지 않았을 때 최댓값은 현재값과 누적값+현재를 통해 판단
		2. 수를 제거했을 경우는 이전 제거하지 않은 누적값과 제거한 누적값 + 현재값을 비교 판단.
		3. 1과 2의 비교를 통해 최댓값을 저장한다.
		

*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][2];
int main()
{
	int ans;
	int num;
	int two;
	cin >> num;

	for (int i = 1; i <= num; i++)
		cin >> arr[i];

	ans = dp[1][0] = dp[1][1] = arr[1];
	for (int i = 2; i <= num; i++) {
		dp[i][0] = dp[i][1] = arr[i];
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans << "\n";

}		