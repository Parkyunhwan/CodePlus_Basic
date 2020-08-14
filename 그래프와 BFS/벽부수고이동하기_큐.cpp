/*
    retry;
*/
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;
typedef pair< pair<int, int>, int> triple;
enum check{USE,NOTUSE};
int dy[]={1,-1,0,0};
int dx[]={0,0,-1,1};
//int dy[]={-1,1,0,0};
//int dx[]={0,0,-1,1};
int N, M;
int map[1001][1001];
int cache[1001][1001][2];
int BFS()
{
    queue<triple> q;
    q.push(make_pair(make_pair(0,0),1));
    cache[0][0][1] = 1;

    while(!q.empty())
    {
        triple tp = q.front();
        int y = tp.first.first;
        int x = tp.first.second;
        int block = tp.second;

        q.pop();
        if(y==N-1 && x==M-1) return cache[y][x][block];

        for(int k=0; k<4; k++){

            int ny = y + dy[k];
            int nx = x + dx[k];

            if( 0 <= ny && ny < N && 0 <= nx && nx < M ){

                if(map[ny][nx]==1  && block ){
                    cache[ny][nx][block-1] = cache[y][x][block] + 1;
                    q.push(make_pair(make_pair(ny,nx), block - 1));
                }
                else if(map[ny][nx]==0 && cache[ny][nx][block]==0){
                    cache[ny][nx][block] = cache[y][x][block] + 1;
                    q.push(make_pair(make_pair(ny,nx), block));
                }
            }
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
    cout << BFS() << "\n";
    return 0;
}