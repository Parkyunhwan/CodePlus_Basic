/*
    https://www.acmicpc.net/problem/2206

    생각
        제일 중요한 건 
        1. 벽을 깬 경로
        2. 벽을 깨지 않은 경로
        두 가지로 나눠서 생각하는 것이다.
        두 가지의 방문 여부를 나누지 않고 계산한다면 벽을 깬 경로가 지나간 곳은 벽을 깨지 않은 곳이 지나가지 못한다.
        따라서, 모든 경우를 커버할 수 없다.

        *?* 속도가 queue보다 priority_queue가 더 느리게 나왔는데 왜지? 
        -> priority_queue는 O(logn)의 삽입속도 , queue는 O(1) 의 속도이므로 queue가 더 빠르다.

        *?* 그럼 최단 경로 구하는데 prioriy_queue를 안써도 되나?
        -> 알고스팟이나 숨바꼭질3은 어떤 경우에는 BFS 단계와 관계없이 기준 값이 바꼈다.
        -> 따라서, queue로는 최소값을 구할수 없다.

        -> 이 문제는 어떤 경우에도 방문시간이 +1 씩 증가하므로 BFS단계와 동일하다.
        -> 따라서, queue로 풀어도 최소값을 구할수 있다. (queue가 빠르므로 이 경우엔 queue를 쓰자) 

        **queue 형식으로 다시 품**

        굉장히 찾기 힘든 오류를 많이 겪었다. 모범 답과 비교해봐도 찾을 수 없었다.
        1. 오류는 대부분 비슷한 변수명에서 찾을 수 있었다
        2. 경계값 확인을 한번 더 확인하자(착각이 있을 수 있다.)

        한 행의 값을 string으로 받아오는 방법을 기억하자!
         map[i][j] = temp[j] - '0'; 을 통해 string 값을 나눠서 입력할 수 있다.
         이 방식은 기존에 cin을 하나씩 하는 것보다 무려 30ms를 절약할 수 있다.
         이는 전체 수행시간에 1/4 을 차지하는 큰 시간이다.
*/
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int N,M;
int map[1001][1001];
int Visited[1001][1001][2];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int BFS()
{
    queue< pair<int , pair<int, int> > > q;
    q.push(make_pair(1,make_pair(0,0)));
    Visited[0][0][1] = 1;
    while(!q.empty()){
        int block = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        if(y==N-1 && x==M-1) return Visited[y][x][block];

        for(int i=0; i<4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
            //if( 0 <= nextY && nextY < N && 0 <= nextX && nextX < M ){
            if(block && map[nextY][nextX]==1){
                Visited[nextY][nextX][block-1] = Visited[y][x][block]+1;
                q.push(make_pair(block-1,make_pair(nextY,nextX)));
            }
            else if(map[nextY][nextX]==0 && Visited[nextY][nextX][block]==0){
                Visited[nextY][nextX][block] = Visited[y][x][block]+1;
                q.push(make_pair(block,make_pair(nextY,nextX)));
            }
            //}
        }
    }
    return -1;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {

        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            map[i][j] = temp[j] - '0';
    }

    /*for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%1d",&map[i][j]);
    */
    cout << BFS() << "\n";
}