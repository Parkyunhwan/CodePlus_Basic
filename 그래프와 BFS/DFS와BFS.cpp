#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
vector<int> v[1001];
vector<int> result;
bool Select[1001]={false,};
int N,M,start;
bool DFS(int idx, int cnt)
{
    if(cnt==N){
        for(int i=0; i<result.size(); i++)
            cout << result[i];
        cout << "\n";
        return true;
    }
    Select[idx] = true;
    for(int i=0; i < v[idx].size(); i++){
        int element = v[idx][i];
        if(Select[element]==true) continue;
            result.push_back(element);
            if(DFS(element, cnt+1))
                return true;
            result.pop_back();
    }
    Select[idx] = false;
    return false;
}
bool BFS(int idx, int cnt)
{
    Select[idx]=true;
    for(int i=0; i<v[idx].size(); i++){
        int element = v[idx][i];
        if(Select[element]==true) continue;
        result.push_back(element);
        if(result.size()==N){
            for(int i=0; i< result.size(); i++)
                cout << result[i] << " ";
            cout << "\n";
            return true;     
        }  
    }
    BFS(result.back(), cnt+1);
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
    result.push_back(start);
    DFS(start,1);
    memset(Select,false,sizeof(Select));
    result.clear();
    result.push_back(start);
    BFS(start,1);
}