#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001][2];
int main()
{
	int num, ans;
	cin >> num;

	for (int i = 1; i <= num; i++)
		scanf("%d", &arr[i]);

	ans = dp[1][0] = dp[1][1] = arr[1];
	for (int i = 2; i <= num; i++) {
		dp[i][0] = dp[i][1] = arr[i];

		// (현재까지 모두 더한 수가 큰 값) 인지 다 버리고 (다시 시작하는 것)이 큰 값인지 비교
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);

		// (현재 숫자를 뺀 값 = 현재까지 삭제없이 더한 수)와 삭제를 제외하고 모두 더한 수 비교
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans << "\n";
}