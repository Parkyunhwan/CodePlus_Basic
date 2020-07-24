/*
    그냥 수열
    근데 입력이 중복이 가능하다.
    어렵다...
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
        if(Select[i]==true) continue;
        Select[i] = true;
        v.push_back(arr[i]);
        DFS(cnt+1);
        v.pop_back();
        Select[i] = false;
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