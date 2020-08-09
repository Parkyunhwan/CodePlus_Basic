/*
    https://www.acmicpc.net/problem/7576
    
    생각
       * 첨 봤을 땐 이전 미로 BFS와는 조금 다르다고 생각했다.
       * 다수의 출발지점이 선정되어 다수개의 BFS가 동작해야 할줄 알았지만
       * 하나의 BFS의 해결할 수 있었다.

    풀이
        1. queue에 어디 부터 시작할지 기록해준다.
        2. BFS를 4방향으로 시작한다.
        3. BFS에 단계를 value배열에 기록한다.
        4. `모두 익지못한다`(-1)를 표현하기위해 시작 value를 1로 두었다.
        5. 따라서 value가 0이면서 map이 -1이 아닌 곳은 토마토가 있으나 익지 않은 곳.

*/
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int M,N;
queue< pair<int, int> > q;
int map[1001][1001];
int val = 1;
int value[1001][1001]={0,};
bool Visited[1001][1001];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
void BFS()
{

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int y = i + dy[k];
            int x = j + dx[k];
            if(y < 0 || y >= N || x < 0 || x >= M) continue;
            if(map[y][x]==0 && Visited[y][x]==false){
                Visited[y][x] = true;
                q.push(make_pair(y,x));
                value[y][x] = value[i][j]+1;
                val = val > (value[i][j]+1) ? val : value[i][j]+1;
            }
        }

    }
}
int main()
{
    bool flag;
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                q.push(make_pair(i,j));
                Visited[i][j]=true;
                value[i][j] = 1;
            }
            else if(map[i][j]==0)
                flag = true;
        }
    }
    if(flag==false){
        cout << "0" << "\n";
        return 0;
    }

    BFS();
    // 디버깅 용 출력
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++)
    //         cout << value[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++)
    //         cout << Visited[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
        {
            if(value[i][j]==0 && map[i][j]!=-1){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << val-1 << "\n";

}