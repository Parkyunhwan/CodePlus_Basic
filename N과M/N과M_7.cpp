/*
    https://www.acmicpc.net/problem/15656
    중복 수열 문제

    * Select 배열을 없애 중복을 검사하지 않는 것이 핵심이다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
const int MAX = 8;
int arr[MAX];
bool Select[MAX];
vector<int> v;
void DFS(int cnt)
{
    if(cnt == M)
    {
        for(vector<int>::size_type i=0; i<v.size(); i++)
        {
                cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++){
        v.push_back(arr[i]);
        DFS(cnt+1);
        v.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i < N; i++)
        cin >> arr[i];
    sort(arr,arr+N);
    DFS(0);
}