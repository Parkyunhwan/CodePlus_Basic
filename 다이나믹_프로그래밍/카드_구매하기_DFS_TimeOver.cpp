/*
    https://www.acmicpc.net/problem/11052

    생각
        단순 숫자나열로는 규칙을 찾기 힘들었다.
        DFS형식의 트리 그림을 그리고 나서야 문제에 대한 해결방법이 떠올랐다.

    풀이
        1. DFS를 1부터 N까지 반복한다.
        2. 1부터 시작하게 되면 1이 들어가는 모든 경우의 수 중 가장 큰 값을 구한다.
        3. 그 다음부턴 그 다음 숫자보다 크거나 같은 수의 조합 중 가장 큰 값을 구한다.
        4. 모든 경우의 수의 결과 중 가장 MAX 값을 출력한다.
    
    오류
        너무 많은 DFS 경우의 수로 인한 타임오버
        DP로 해결해야 하는 문제.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[10001];
int d[1001];
int k;
int maximum=0;
void DFS(int num,int val)
{
    if(num==N){
        maximum = max(maximum,val);
        return;
    }
    
    for(int i=k; i<=N; i++){
        if(num+i<=N){
            DFS(num+i, val + p[i]);        
        }
    }
}
int main()
{
    cin >> N;
    for(int i=1; i <= N; i++)
        cin >> p[i];
    for(int i=1; i<=N; i++){
        k = i;
        DFS(i,p[i]);
    }
    cout << maximum << "\n";
}