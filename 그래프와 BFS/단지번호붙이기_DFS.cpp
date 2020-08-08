/*
    https://www.acmicpc.net/problem/2667

    생각
        1. 갈 수 있는 방향은 위 아래 왼쪽 오른쪽 방향이 있다는 것을 명심하자.
        2. 처음에 사람이 사는 집을 1로 표기 한다.
        3. 그 후 이미 방문한 집은 0으로 표기해 사람이 없는 집과 똑같이 취급한다. (즉, 더 이상 방문 하지 않는다.)
        4. vector<int> result를 통해 단지 당 집 수를 기록한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
enum direction{LEFT, RIGHT, TOP, BOTTOM};
enum check{YES,NO};
using namespace std;
int N;
int room;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<int> result;
int map[26][26];
void DFS(int si,int sj){
    map[si][sj]=YES; // 방문 했다는 의미로 YES(=0) 으로 바꿔줌. 다시 체크 하지 않게됨
    room++;
    // for(int k=0;k<4;k++)
    //   {
    //         if(si + dy[k] < 0 || si + dy[k] >= N || sj + dx[k] < 0 || sj + dx[k] >= N)continue;
    //         if(map[si + dy[k]][sj + dx[k]] == 1)DFS(si + dy[k], sj + dx[k]); // 0 : si-1,sj 1 : si+1, sj 2 : si, sj-1 3 : si sj+1
    //   }
    for(int i=0; i<4; i++){
        switch(i)
        {
            case LEFT:
                if(sj-1 < 0) break;
                if(map[si][sj-1]==NO)
                    DFS(si,sj-1);
                break;
            case RIGHT:
                if(sj+1 >= N) break;
                if(map[si][sj+1]==NO)
                    DFS(si,sj+1);
                break;
            case TOP:
                if(si-1 < 0) break;
                if(map[si-1][sj]==NO)
                    DFS(si-1,sj);
                break;
            case BOTTOM:
                if(si+1 >= N) break;
                if(map[si+1][sj]==NO)
                    DFS(si+1,sj);
                break;
        }

    }
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    for(int i=0; i < N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 1){
                room = 0;
                DFS(i,j);
                result.push_back(room);
            }
        }
    }
    sort(result.begin(),result.end());
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++)
        cout << result[i] << "\n";
}