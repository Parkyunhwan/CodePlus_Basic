#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> vec[1001];
bool Visited[1001]={false,};
void DFS(int idx) // bool 로 했을 시 오류 발생! 안 쓸거면 void로! 조심하자.
{
    Visited[idx] = true;
    for(int i=0; i<vec[idx].size(); i++){
        int next = vec[idx][i];
        if(Visited[next]==true) continue;
        //Visited[next] = true; 어차피 DFS 시작시 해주기 때문에 필요가 없는 부분!
        DFS(next);
    }
}
int main()
{
    int result=0;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for(int i=1; i<=N;i++){
        if(Visited[i]==false){
            DFS(i);
            result++;    
        }
    }
    cout << result << "\n";
}