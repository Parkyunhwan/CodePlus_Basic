/*
    https://www.acmicpc.net/problem/2206

    생각
        제일 중요한 건 
        1. 벽을 깬 경로
        2. 벽을 깨지 않은 경로
        두 가지로 나눠서 생각하는 것이다.
        두 가지의 방문 여부를 나누지 않고 계산한다면 벽을 깬 경로가 지나간 곳은 벽을 깨지 않은 곳이 지나가지 못한다.
        따라서, 모든 경우를 커버할 수 없다.

        속도가 queue보다 priority_queue가 더 느리게 나왔는데 왜지?
        그리고 최단 경로 구하는데 prioriy_queue를 안써도 되나?  
        **queue 형식으로 풀어보기
*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<pair<int,bool>, pair<int, int> > Doublepair;
priority_queue< Doublepair, vector<Doublepair>, greater<Doublepair> > q;
int N,M;
int map[1001][1001];
bool Visited[1001][1001][2];
int dy[]={1,-1,0,0};
int dx[]={0,0,-1,1};
int val = 0;
bool BFS()
{
    Doublepair tp = make_pair(make_pair(1,true),make_pair(0,0)); // 횟수, 벽부술기회, y, x
    q.push(tp);
    Visited[0][0][1]=true;
    while(!q.empty())
    {
        Doublepair dp = q.top();
        int time = dp.first.first;
        bool ability = dp.first.second;
        int i = dp.second.first;
        int j = dp.second.second;
        if(i==N-1 && j==M-1){val = time; return true;}
        q.pop();
        for(int k=0; k<4; k++){
            int y = i + dy[k]; int x = j + dx[k];
            if(y < 0 || y >= N || x < 0 || x >= M ) continue;
            if(ability==true && map[y][x]==1 && Visited[y][x][ability]==false){
                Visited[y][x][0] = true;
                q.push( make_pair(make_pair(time+1,false),make_pair(y,x)) );
            }
            if(map[y][x]==0 && Visited[y][x][ability]==false){
                Visited[y][x][ability] = true;
                q.push( make_pair(make_pair(time+1,ability),make_pair(y,x)) );
            }
        }
    }
    return false;
}
int main()
{   
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        for(int j=0; j< M; j++)
            scanf("%1d",&map[i][j]);

    bool result = BFS();
    if(result==true)
        cout << val << "\n";
    else
        cout << "-1" << "\n";
    
}