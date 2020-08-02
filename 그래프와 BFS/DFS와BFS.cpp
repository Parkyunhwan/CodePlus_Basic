#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[1000];

int N,M,start;
void DFS(int idx, int cnt)
{
    if(cnt==N){
        return;
    }
    for(int i=0; i < v[start].size(); i++){
        
    }

}
int main()
{
    cin >> N >> M >> start;
    for(int i=0; i<M; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<N; i++)
        sort(v[i].begin(), v[i].end());
    DFS(start,1);
}