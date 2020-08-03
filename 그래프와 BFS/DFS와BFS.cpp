/*
    https://www.acmicpc.net/submit/1260

    [다시 풀기]

    DFS
    1. DFS, BFS 둘 다 cnt가 필요없는 문제
    2. cnt가 필요없는 이유는 이미 거친 정점은 다시 보지 않기 때문..? 어차피 모든 길을 탐색함
    3. 거치지 않은 정점만 출력해준다.

    BFS
    1. BFS를 DFS처럼 푸니 시간초과가 발생함
    2. vector를 queue로 바꿔서 해결
    3. 거치지 않은 정점은 출력하며 모든 정점을 BFS 방법으로 탐색함

    ** Sort시 주의사항 : vector의 값이 1부터 들어가므로 <= N을 포함한 sort를 해줘야함.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
vector<int> v[1001];
vector<int> result;
bool Select[1001]={false,};
int N,M,start;
queue<int> q;
void DFS(int idx)
{
    Select[idx] = true;
    for(int i=0; i < v[idx].size(); i++){
        int element = v[idx][i];
        if(Select[element]==true) continue;
        cout << element << " ";
        DFS(element);
    }
}
void BFS(int idx)
{
    q.push(idx);
    Select[idx]=true;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i=0; i<v[n].size(); i++){
            int a = v[n][i];
            if(Select[ a ]==true) continue;
            Select[ a ]=true;
            q.push(a);
            cout << a << " ";
        }
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
    for(int i=1; i<=N; i++)
        sort(v[i].begin(), v[i].end());
    cout << start << " ";
    DFS(start);
    cout << "\n";
    memset(Select,false,sizeof(Select));
    cout << start << " ";
    BFS(start);
}