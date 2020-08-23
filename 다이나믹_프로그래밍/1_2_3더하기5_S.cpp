/*
    https://www.acmicpc.net/problem/15990

    생각 
        못 품.
        점화식을 구할 수 가 없었다.

        점화식을 구하기 위해선 이전에 어떤 값들이 현재 값의 1,2,3으로 끝날 수 있는지
        파악해야 했다.
    
    풀이   
        마지막으로 오는 수가 1이라면 -> 그 전 숫자는 2 or 3
        마지막으로 오는 수가 2라면   -> 그 전 숫자는 1 or 3
        마지막으로 오는 수가 3이라면 -> 그 전 숫자는 1 or 2

        d[n][1] = d[n-1][2] + d[n-1][3]
        d[n][2] = d[n-2][1] + d[n-2][3]
        d[n][3] = d[n-3][1] + d[n-3][2]
    
    추가
        * 여러 입력을 받을 때 속도를 위해 모든 값을 먼저 구해 놓기
        * cin은 굉장히 느리니 반복입력 받을 시 반드시 scanf or sync(false)
*/
#include <iostream>

using namespace std;

long long d[100001][4];
long long mod = 1e9 + 9;
int main()
{
// ios_base :: sync_with_stdio(false); 
// cin.tie(NULL); 
// cout.tie(NULL);
    int num;

    cin >> num;
    //scanf("%d",&num);

    d[1][1] = 1;
    d[2][2] = 1;
    d[3][1] = d[3][2] = d[3][3] = 1;

    // 매번 검사하지 않기 위한 선 검사 방법..
    for(int i=4; i<=100001; i++){
        d[i][1] = (d[i-1][2] + d[i-1][3]) % mod;
        d[i][2] = (d[i-2][1] + d[i-2][3]) % mod;
        d[i][3] = (d[i-3][1] + d[i-3][2]) % mod;
    }

    for(int i=0; i<num; i++){
        int N;

        // cin 과 scanf의 속도 차가 무려 40배나 발생했다 약 80ms 정도
        // sync_with_stdio(false) 를 쓰면 속도가 같아진다.
        // 하지만 이것은 싱글쓰레드에서만 작동하고 scanf와 printf와 같이 사용 불가이다. 실무 사용 금지!
        // 반복된 cin은 자제 해야 겟다.
        cin >> N;
        //scanf("%d",&N);

        long long sum = (d[N][1] + d[N][2] + d[N][3]) % mod;
        cout << sum << "\n";
        //printf("%d\n",(d[N][1] + d[N][2] + d[N][3]) % mod);
    }
}