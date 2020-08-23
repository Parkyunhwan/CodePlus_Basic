/*
    https://www.acmicpc.net/problem/15988

    생각
        1,2,3더하기 1 과 점화식은 같다.
        하지만, 숫자가 커져서 int로는 숫자의 합을 표현하는 것이 불가능하다.
        결과 값은 mod로 인해 int 범위를 넘지 않지만 중간 계산 값이 그 크기를 넘게 된다.

        * int -> (-2,147,483,648 ~ 2,147,483,647) 20억정도 (4byte 기준)
        * long long -> (-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807) 매우 크다. (8바이트)
        
        따라서, 합을 mod 하려면 long long 자료형을 사용해서 문제를 풀어야 한다.

        --> int자료형으로 풀려면 중간 계산 과정에서 mod를 취해줘서 더하면 된다. (방법 주석처리해놈)
        --> 메모리를 절약할 수 있지만 계산 과정이 추가되어 시간이 증가하는 trade-off 가 발생하게 된다.
*/
#include <iostream>

using namespace std;
//int d[1000001];
long long d[1000001];
int main()
{
    int num;
    int n;
    cin >> num;
    d[1]=1;
    d[2]=2;
    d[3]=4;
    while(num--){
        cin >> n;
        for(int i=4; i<=n; i++){
            d[i]=(d[i-1]+d[i-2]+d[i-3])%1000000009;
            //d[i]=(((d[i-1]+d[i-2])%1000000009) + d[i-3])%1000000009;
        }
        cout << d[n] << "\n";
    }
}