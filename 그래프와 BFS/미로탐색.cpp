/*
    https://www.acmicpc.net/problem/2178
    일단 최단경로 문제를 DFS로 풀려고하면 굉장히 시간이 많이 걸린다고 한다.
    BFS로 풀어야만 한다.

    오류...

    진짜 실수투성이 였던 문제..

    알고리즘은 BFS이고 BFS queue에 넣을 때 현재까지 지나온 값을 기록해주면 되는 문제 였다.

    하지만 i , j 의 표현에 있어서 i를 x로 j 를 y로 오인하는 경우가 많았다.
    정확한 정의가 필요했다.
    i -> y축
    j -> x축
    우리가 보통 생각 [X축][Y축] ( X )
    배열에 들어갈 땐 map[Y축][X축] ( O )

    기억하자

*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int height, width;
int map[101][101];
int value[101][101];
bool Visited[101][101];
// int dx[]={0,0,-1,1};
// int dy[]={-1,1,0,0};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cnt = 1;
queue< pair<int, int> > q;
void BFS(int i , int j)
{
    map[i][j]=0;
    //Visited[i][j]=true;
    value[i][j]=cnt;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int si= q.front().first;
        int sj= q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int X = sj + dx[k];
            int Y = si + dy[k];
            if(Y < 0 || Y >= height || X  < 0 || X  >= width) continue;
            if(map[Y][X] == 1 ){//&& Visited[sj+dx[k]][si+dy[k]]==false
                map[Y][X]=0;
                //Visited[sj+dx[k]][si+dy[k]]=true;
                value[Y][X]=value[si][sj]+1;
                q.push(make_pair(Y,X));
            }
        }    
    }
}
int main()
{

    cin >> height >> width;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            scanf("%1d",&map[i][j]);
        }
    } 
    
    BFS(0,0);
   /* for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout << value[i][j];
        }
        cout << "\n";
    }*/
    cout <<  value[height-1][width-1] << "\n";

}

