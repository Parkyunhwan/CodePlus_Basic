/*
    https://www.acmicpc.net/problem/11055

    이전 <증가부분수열> 시리즈랑 풀이 방식이 같다.
    현재 n 의 최댓값은 현재 n의값보다 작은 수의 최댓값에 현재값을 더한 것이다.

    이전 시리즈와 다르게 갯수를 세는 것이 아닌 총 합을 구해야 하므로
    +1 대신 +arr[i] 를 해주면 되는 문제였다.
*/
#include <iostream>

using namespace std;
int arr[1001];
int d[1001];
int main()
{
    int num;
    int result = 0;
    cin >> num;

    for(int i=1; i <=num; i++)
        cin >> arr[i];

    for(int i=1; i<=num; i++){
        int min = 0;
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j] && min < d[j])
                min = d[j];
        }
        d[i] = min + arr[i];
        if(d[i] > result)
            result = d[i];
    } 
    cout << result << "\n";
}