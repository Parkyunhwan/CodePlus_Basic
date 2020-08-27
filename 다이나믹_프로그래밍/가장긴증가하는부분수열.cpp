/*
    https://www.acmicpc.net/problem/11053 
    [Search]

    생각
        전의 값을 어떻게 하면 이용할 수 있는지 고민을 했다.
        이전의 DP와 다른 점은 이미 기록한 누적값들을 다시 한번 모두 확인해가며 그 다음 dp값을 결정한다는 점이였다.
        -> 이 부분이 이게 과연 dp인가 하는 의문을 들게했고 생각의 발전을 막았던 것 같다.
    
    풀이
        1. 최댓값을 구하기 위해서는 현재 값보다 작은 값중에서 누적된 값이 가장 큰 것을 구한다.
        2. 그 값에 +1을 한다.
        3. n까지 누적 최대값을 구했다면 1~n까지 max값을 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int arr[1001];
int main()
{
    int num;
    int max = 0;
    scanf("%d",&num);
    for(int i=1; i<=num; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=num; i++)
    {
        int min = 0;
        for(int j=1; j<i; j++){
            if(arr[j] < arr[i] && d[j] > min)
                min = d[j];
        }
        d[i] = min + 1;
        if(d[i] > max)
            max = d[i];
    }
    cout << max << "\n";
    // for(int i=1; i<=num; i++){
    //     d[i]=1;
    //     for(int j=1; j<=i; j++){
    //         if( arr[j] < arr[i] && d[j]+1 > d[i] ) d[i] = d[j] + 1;
    //     }
    // }
    // int result=0;
    // for(int i=1; i<=num; i++)
    //     result = max(result, d[i]);
    // cout << result << "\n";

}