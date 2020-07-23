/*
    https://www.acmicpc.net/problem/15652
    문제 자체는 1. 중복수열 2. 비내림차순 조건이였지만
    결국, 중복조합을 구하는 문제였다.
*/
#include <iostream>
using namespace std;
int N,M;
int arr[8];
int Select[8];
void DFS(int cnt,int idx)
{
    if(cnt == M){
        for(int i=0; i<M;i++){
            cout << Select[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=idx; i<N; i++){
        Select[cnt]=i+1;
        DFS(cnt+1, i);
    }


}
int main()
{
    cin >> N >> M;

    for(int i=0; i < N; i++)
        arr[i] = i+1;
    
    DFS(0,0);
}