/*
    https://www.acmicpc.net/problem/14002

    생각
        이전 버전 1문제랑 풀이는 같다.
        현재 값보다 작은 가장 큰 누적값에 1을 더하면 현재 누적 최댓값이다.
    
    풀이
        버전 1에 path를 추가해야 했다.

        1. 현재 값보다 작은 누적값의 순서 번호를 기억해둠
        2. 기억해둔 번호를 현재 path값에 기록 (이전 path가 어딘지 확인 가능)
        3. 마지막 순서를 기억해두고 첫번째 순서가 나올때 까지 스택에 기록
        4. 스택을 꺼내면서 출력하면 원상태로 출력가능
*/
#include <iostream>
#include <stack>
using namespace std;
int d[1001];
int arr[1001];
int path[1001]={0,};
int main()
{
    int num,last;
    stack<int> s;
    int result = 0;
    path[1]=0;
    cin >> num;
    for(int i=1; i<=num; i++)
        cin >> arr[i];

    for(int i=1; i<=num; i++){
        int min = 0;
        int p=0;
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j] && min < d[j]){
                min = d[j];
                p = j;
            }
        }
        path[i] = p;
        d[i] = min + 1;
        if(result < d[i]){
            result = d[i];
            last = i;
        }
    } 

    cout << result << "\n";
    s.push(last);
    while(path[last]){
        //cout << last <<" "<< path[last] << "\n";
        s.push(path[last]);
        last = path[last];
    }
    while(!s.empty()){
        cout << arr[s.top()] << " ";
        s.pop();
    }
    cout << "\n";
}