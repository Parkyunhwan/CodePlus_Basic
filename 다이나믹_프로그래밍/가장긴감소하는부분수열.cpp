/*
    https://www.acmicpc.net/problem/11722

    생각
        * 부분수열 문제와 같은 유형이다.
        * 단지 현재값보다 큰 값이면서 누적값이 min보다 큰 값을 골라서 적용시킨다.
        * dp[N] 보다 min이 작으면 dp[N]이 최댓값이다.
    풀이
        * 부호 방향만 바뀌였을 뿐 나머지는 같다.
*/
#include <iostream>

using namespace std;
int arr[1001];
int dp[1001];
int main()
{
    int num;
    int result = 0;
    cin >> num;

    for(int i=1; i<=num; i++)
        cin >> arr[i];
    
    for(int i=1; i<=num; i++){
        int min = 0;
        for(int j=1; j < i; j++){
            if(arr[i] < arr[j] && min < dp[j])
                min = dp[j];
        }
        dp[i] = min + 1;
        if(result < dp[i])
            result = dp[i];
    }

    cout << result << "\n";
    
}