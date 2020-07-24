/*
    https://www.acmicpc.net/problem/15655
    
    순열로 문제를 줬지만
    조건에 오름차순이 있었기에
    조합을 구하는 문제였다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
const int MAX = 8;
int arr[MAX];
bool Select[MAX];
void DFS(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0; i<N; i++)
        {
            if(Select[i]==true){
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i < N; i++){
        if(Select[i]==true) continue;
        Select[i] = true;
        DFS(cnt+1, i);
        Select[i] = false;
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