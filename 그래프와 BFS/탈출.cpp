#include <iostream>
#include <utility>
#include <string>
#include <queue>

using namespace std;
int R, C;
char map[51][51];
enum character {HEDGEHOG,WATER};
const int flood = -1;
int Visited[51][51][2];
int Vx, Vy;
queue< pair< pair<int, int>, int > > q;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int BFS()
{
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;

        int role = q.front().second;

        if(role==HEDGEHOG && Visited[i][j][WATER]==flood){cout << i << j << "\n"; return -1;}
        if(role==HEDGEHOG && i == Vy && j == Vx) return Visited[i][j][HEDGEHOG];
        q.pop();
        for(int k=0; k<4; k++){
            int Y = i + dy[k];
            int X = j + dx[k];
            if(Y < 0 || Y >= R || X < 0 || X >= C || map[Y][X]=='X') continue;                

            if(role==WATER && Visited[Y][X][WATER]==0){
                Visited[Y][X][WATER] = flood;
                q.push(make_pair(make_pair(Y,X), WATER));
                        cout << Y << " " << X << " " << role << "\n";
            }
            if(role==HEDGEHOG && Visited[Y][X][HEDGEHOG]==0 && Visited[Y][X][WATER]==0){
                Visited[Y][X][HEDGEHOG] = Visited[i][j][HEDGEHOG] + 1;
                q.push(make_pair(make_pair(Y,X),HEDGEHOG));
                cout << Y << " " << X << " " << role << "\n";
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
                Visited[i][j][WATER]=flood;
                q.push(make_pair( make_pair(i,j),WATER) );
            }
            else if(map[i][j]=='S'){
                q.push(make_pair( make_pair(i,j),HEDGEHOG) );
            }
            else if(map[i][j]=='D'){
                Vy = i; Vx = j;
            }
        }
    }
    int val;
    val = BFS();
    if(val)
        cout << val << "\n";
    else
    {
        cout << "KAKTUS" << "\n";    
    }
    // for(int i=0; i<R; i++){
    //     for(int j=0; j<C; j++){
    //         printf("%c",map[i][j]);
    //     }
    //     cout << "\n";}
}