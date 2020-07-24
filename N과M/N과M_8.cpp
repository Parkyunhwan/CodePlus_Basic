/*
    https://www.acmicpc.net/problem/15657
    
    중복수열 + 비내림차순 조건 = 중복 조합!

    Select 배열을 int 형으로 변환해서 숫자를 저장한다
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
const int MAX = 8;
int arr[MAX];
int Select[MAX];
void DFS(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0; i<M; i++)
        {
                cout << Select[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i < N; i++){
        Select[cnt]=arr[i];
        DFS(cnt+1, i);
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    sort(arr,arr+N);   
    DFS(0,0);
}