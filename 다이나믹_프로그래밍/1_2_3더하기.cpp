/*
    https://www.acmicpc.net/problem/9095

    생각 
        점화식을 구해보려고 규칙 시도를 해봤지만 찾지 못했다.
        이전 값에서 추가될 수 있는 것이 무엇인지 생각하고
        그 부분을 이용해 저장된 값에 1,2,3을 추가해 구하는 문제이다.
    
    풀이
        n번째 숫자는 n-1에 1을 더한 숫자이다.
                    n-2에 2를 더한 숫자이다.
                    n-3에 3을 더한 숫자이다.

        따라서, n번째 숫자는 n-1, n-2, n-3의 구하는 경우의 수의 합이다.
*/
#include <iostream>

using namespace std;
int d[11];
int c[12];
int result;
int main()
{
    int n;
    int num;
    cin >> num;

    d[1]=1;
    d[2]=2;
    d[3]=4;
    while(num--){
        cin >> n;
        for(int i=4; i<=n; i++){
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }
        cout << d[n] << "\n";
    }
}