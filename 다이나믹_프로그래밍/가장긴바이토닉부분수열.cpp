/*
    https://www.acmicpc.net/submit/11054

    생각
        * 바이토닉 오름차순과 내림차순의 혼합 문제 였다.
        * 한번은 오름차순으로 구하고 한번은 내림차순으로 구하면 되는 문제였다.
        * 나는 생각을 하다가 오름차순을 앞뒤로 해서 풀었다.

    풀이
        * 오름차순 dp 를 dp[0] 에 저장
        * 내림차순 dp 를 dp[1] 에 저장
        * dp[0] + dp[1] - 1 의 최댓값을 출력    
*/
#include <iostream>

using namespace std;
int dp[1001][2];
int arr[1001];
int maximum(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    int num;
    int result = 0;
    cin >> num;
    for(int i=1; i<=num; i++){
        cin >> arr[i]; 
    }
    
    for(int i=1; i <= num; i++){
        int min = 0;
        for(int j=1; j < i; j++){
            if(arr[i] > arr[j] && min < dp[j][0])
                min = dp[j][0];
        }
        dp[i][0] = min + 1;
    }

    for(int i=num; i>=1; i--){
        int min=0;
        for(int j=num; j > i; j--){
            if(arr[i] > arr[j] && min < dp[j][1])
                min = dp[j][1];
        }
        dp[i][1] = min + 1;
    }

    for(int i=1; i<=num; i++){
        result = maximum(result, dp[i][0] + dp[i][1]-1);
    }

    cout << result << "\n";
}