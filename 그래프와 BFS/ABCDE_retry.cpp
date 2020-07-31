#include <iostream>
#include <vector>
using namespace std;
int N, M;
int a, b;
bool visit[2000];
vector<int> v[2000];
void DFS(int idx, int cnt)
{
    if(cnt == 5)
    {
        cout << 1 << "\n";
        exit(0);
    }
    visit[idx] = true;
    for(vector<int>::size_type i=0; i < v[idx].size(); i++)
    {
        int next = v[idx][i];
        if(visit[next]==true) continue;
        DFS(next, cnt+1);

    }
    visit[idx] = false;
}
int main()
{
    cin >> N >> M;
    for(int i=0; i < M; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<N; i++){
        DFS(i, 1);
    }
    cout << "0" << "\n";
}