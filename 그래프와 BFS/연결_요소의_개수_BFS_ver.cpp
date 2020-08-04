/*
    https://www.acmicpc.net/problem/11724

    1. 연결요소는 한 그래프내에 서로 아무런 관련이 없는 집합이라고 볼 수 있다.
    2. BFS나 DFS 탐색을 통해 끊기지 않고 찾을 수 모든 원소가 연결요소이다.
    3. 따라서, 모든 원소에 대해 BFS를 수행하며 BFS 수행 횟수가 곧 연결요소의 갯수이다.
    4. 이것을 모든 원소를 방문할 때 까지 반복하도록 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int flag=0;
int N,M;
queue<int> q;
vector<int> vec[1001];
bool Visited[1001]={false,};
void BFS(int idx)
{
    q.push(idx);
    Visited[idx]=true;
    while(!q.empty())
    {
        int next = q.front();
        q.pop();
        for(int i=0; i<vec[next].size(); i++){
            int element = vec[next][i];
            if(Visited[element]==true) continue;
            Visited[element]=true; flag++;
            q.push(element);
        }
    }
}
int main()
{
    int ak;
    int result=0;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    while(1){
        if(flag==N)
            break;
        for(int i=1; i<=N; i++){
            if(Visited[i]==false){
                ak = i;
                break;        
            }
        }
        flag++;       
        BFS(ak);
        result++;
    }
    cout << result << "\n";
}