/*
    https://www.acmicpc.net/problem/15650

    C++14 컴파일에러
    bool select[8] 안되나 bool Select[8]은 된다.

    문제는 순열을 구하라 했으나 순서가 오름차순으로 정해졌으므로
    조합을 구하면 된다.
*/
#include <iostream>
using namespace std;
//#define MAX 8
int N,M;
int arr[8];
bool Select[8];
void DFS(int cnt,int idx)
{
    if(cnt == M)
    {
        for(int i=0; i < N; i++){
            if(Select[i]==true)
                cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for(int i=idx; i<N; i++){
        if(Select[i]==true) continue;
        Select[i]=true;

        DFS(cnt+1, i);
        Select[i]=false;
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
        arr[i]=i+1;
    DFS(0,0);
}