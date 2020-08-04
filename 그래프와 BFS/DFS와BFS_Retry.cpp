#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> v[1001];
bool Visited[1001];
int N,M,start;
queue<int> q;
void DFS(int idx)
{
    Visited[idx]=true;
    for(int i=0; i<v[idx].size(); i++)
    {
        int next = v[idx][i];
        if(Visited[next]==true) continue;
        cout << next << " ";
        DFS(next);
    }
}
void BFS(int idx)
{
    Visited[idx]=true;
    q.push(idx);
    while(!q.empty())
    {
        int next = q.front();
        q.pop();
        for(int i=0; i<v[next].size(); i++){
            int element = v[next][i];
            if(Visited[element]==true) continue;
            cout << element << " ";
            Visited[element] = true;
            q.push(element);
        }
    }    
}
int main()
{
    int a,b;
    cin >> N >> M >> start;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=N;i++)
        sort(v[i].begin(),v[i].end());
    cout << start << " ";
    DFS(start);
    cout << "\n";
    memset(Visited,false,sizeof(Visited));
    cout << start << " ";
    BFS(start);
    cout << "\n";
}


