/*
    https://www.acmicpc.net/problem/2193

    *생각
        규칙성을 찾아 점화식을 구한다.

    *오류
       < 오버플로우 오류 >
       int는 10자리 수밖에 표현못함
       long long은 19자리 가능

       자릿수가 늘어날 때마다 숫자는 최소 2배씩 증가하므로
       2^90 = 10^18
       ---> 2^10이 10^2과 비슷한 숫자
       ---> (2^10)^9 는 (10^2)^9 = 10^18이라고 볼수 있다.
       따라서, int 대신 long long을 써야만 한다.
    
*/
#include <iostream>

using namespace std;
long long d[91][2];
int main()
{
    d[1][0] = 0;
    d[1][1] = 1;
    int N;
    cin >> N;

    for(int i=2; i<=N; i++){
        for(int j=0; j<2;j++){
            d[i][0] = d[i-1][0] + d[i-1][1];
            d[i][1] = d[i-1][0];
        }
    }
    cout << d[N][0] + d[N][1] << "\n";
}