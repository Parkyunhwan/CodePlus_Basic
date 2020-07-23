/*
    중복 수열 문제
*/
#include <iostream>
#include <vector>
using namespace std;
int N,M;
const int MAX = 7;
int Select[MAX];
int arr[MAX];
vector<int> v;
void DFS(int cnt)
{
    if(cnt==M)
    {
        for(vector<int>::size_type i=0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++)
    {
        v.push_back(i+1);
        DFS(cnt + 1);
        v.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i < N; i++)
        arr[i] = i+1;

    DFS(0);
}