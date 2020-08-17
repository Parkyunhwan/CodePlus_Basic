/*
    https://www.acmicpc.net/problem/3055
    
    생각
        1. 물과 고슴도치가 동시에 시작한다.    
        2. 물이 도착한 시간에 동시에 고슴도치가 도착해서 안된다. 무조건 고슴도치가 빨라야 한다.
    
    구현
        1. 물이 각 구역을 덮치는 시간을 계산한다.
        2. 고슴도치가 구역에 도착하는 시간이 물보다 빨라야 하며 물이 아예 안 왔을 경우도 포함해야 한다.
        3. 나머지는 전형적인 BFS이다.

    반례
        * 반례는 종이에 써가면서 차분히 찾아보자.
        * 인터넷을 찾아보면 생각하는 의미가 없다.
*/
#include <iostream>
#include <utility>
#include <string>
#include <queue>

using namespace std;
int R, C;
char map[51][51];
enum character {HEDGEHOG,WATER};
const int flood = -1;
int WaterVisited[51][51];
int HedVisited[51][51];
int Vx, Vy;
queue< pair< int, int > > wq, hq;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int BFS()
{
    while(!wq.empty()){
        int i = wq.front().first;
        int j = wq.front().second;
        wq.pop();
        for(int k=0; k<4; k++){
            int Y = i + dy[k];
            int X = j + dx[k];
            if(Y < 0 || Y >= R || X < 0 || X >= C) continue;
            if(WaterVisited[Y][X]==0 && map[Y][X]=='.'){
                WaterVisited[Y][X] = WaterVisited[i][j]+1;
                wq.push(make_pair(Y,X));
            }
        }
    }


    while(!hq.empty()){
        int i = hq.front().first;
        int j = hq.front().second;
        hq.pop();
        if(i==Vy && j==Vx){return HedVisited[i][j];}
        for(int k=0; k<4; k++){
            int Y = i + dy[k];
            int X = j + dx[k];
            if(Y < 0 || Y >= R || X < 0 || X >= C) continue;
            if(HedVisited[Y][X]==0 && map[Y][X]=='.'){
                if(WaterVisited[Y][X] > HedVisited[i][j]+1 || WaterVisited[Y][X]==0){
                    HedVisited[Y][X] = HedVisited[i][j]+1;
                    hq.push(make_pair(Y,X));
                }
            }
            else if(map[Y][X]=='D'){
                return HedVisited[i][j]+1;
            }
        }
    }

    return -1;
}
int main()
{
    cin >> R >> C;
    for(int i=0; i<R; i++){
        string temp;
        cin >> temp;

        for(int j=0; j<C; j++){
            map[i][j] = temp[j];
            if(map[i][j]=='*'){
                WaterVisited[i][j]=0;
                wq.push(make_pair(i,j));
            }
            else if(map[i][j]=='S'){
                HedVisited[i][j]=0;
                hq.push(make_pair(i,j));
            }
            else if(map[i][j]=='D'){
                Vy = i; Vx = j;
            }
        }
    }
    int val;
    val = BFS();
    // cout << "WaterRoad" << "\n";
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++)
    //         cout << WaterVisited[i][j];
    // cout << "\n";
    // }
    // cout << "HedRoad" << "\n";
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++)
    //         cout << HedVisited[i][j];
    // cout << "\n";
    // }
    if(val>0)
        cout << val << "\n";
    else
    {
        cout << "KAKTUS" << "\n";    
    }
}