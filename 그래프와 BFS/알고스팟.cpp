/*
    https://www.acmicpc.net/problem/1261
    
    생각
        그 전 숨바꼭질3을 풀어봤기 때문에 어렵지 않게 풀 수 있는 문제였다.
        바뀐 내용은 2차원에서 3차원으로 변화이다.
        따라서, pair로 2가지 내용이 아닌 3가지 값(벽을 뚫은 횟수, y , x)를 저장해야 한다.
        추가로, 벽이 있을 때는 횟수를 늘려주고 없다면 그대로 두는 문제였다.
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair< int, pair<int,int> > triplepair;
vector<triplepair> w;
priority_queue<triplepair, vector<triplepair>,greater<triplepair> > q;
int map[101][101];
int Visited[101][101];
int N, M;
int val=0;
int dy[]={1,-1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    cin >> M >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%1d",&map[i][j]);
    triplepair tq;
    tq.first = val;
    tq.second.first = 0;
    tq.second.second = 0;
    q.push(tq);
    while(!q.empty())
    {
        val = q.top().first;
        int y = q.top().second.first;
        int x = q.top().second.second;
        //cout << val << y << x<< "\n";
        if(y==N-1 && x==M-1) break;
        Visited[y][x] = true;
        q.pop();
        for(int k=0; k < 4; k++){
            if(y + dy[k] < 0 || y + dy[k] >= N || x + dx[k] < 0 || x + dx[k] >= M) continue;
            if(Visited[y+dy[k]][x+dx[k]]==true) continue;
            Visited[y+dy[k]][x+dx[k]]=true;
            triplepair tq;
            if(map[y+dy[k]][x+dx[k]]==1){
                //cout << y+dy[k] << " " << x+dx[k] << " " <<val+1 << "\n";
                tq = make_pair(val+1,make_pair(y+dy[k],x+dx[k]));
            }
            else
                tq = make_pair(val,make_pair(y+dy[k],x+dx[k]));
            
            q.push(tq);
        }
    }
    cout << val << "\n";
}