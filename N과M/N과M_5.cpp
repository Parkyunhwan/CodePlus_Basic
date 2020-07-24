/*
    1. 처음에 배열로 출력을 시도 했다가 실패함.
        배열로 출력하면 고정된 순서로 밖에 출력하지 못한다.
    
    2. vector<int>를 이용해서 저장된 순서로 출력을 하자
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 8;
int N, M;
int arr[MAX];
bool Select[MAX];
vector<int> v;
void DFS(int cnt)
{
    if(cnt == M)
    {
        for(vector<int>::size_type i=0; i<v.size(); i++){
                cout << v[i] << " ";
        }
        cout << "\n"; 
        return;
    }
    
    for(int i=0; i<N; i++){
        if(Select[i]==true) continue;
        Select[i]=true;
        v.push_back(arr[i]);
        DFS(cnt+1);
        v.pop_back();
        Select[i]=false;
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