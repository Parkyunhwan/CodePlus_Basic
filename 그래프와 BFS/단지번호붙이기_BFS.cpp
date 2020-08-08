/*
    https://www.acmicpc.net/problem/2667

    오류 
        enum을 쓸 때 확실한 언어 표현이 아니면 오류를 유발할 수 있음에 명심하자

*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
enum direction{LEFT, RIGHT, TOP, BOTTOM};
enum check{NO,YES};//YES : 사람이 살거나 방문하지 않은 곳, NO : 방문 했거나 사람이 살지 않는 곳
using namespace std;
int N;
int room;
queue< pair<int, int> > q;
vector<int> result;
int map[26][26];
void BFS(int i, int j)
{
    map[i][j] = NO;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int si = q.front().first;
        int sj = q.front().second;
        q.pop();
        //map[i][j] = NO;
        room++;
        for(int k=0; k<4; k++){
            switch(k)
            {
                case LEFT:
                    if(sj-1<0) break;
                        if(map[si][sj-1]==YES){
                            map[si][sj-1] = NO;
                            q.push(make_pair(si, sj-1));
                        }
                    break;
                case RIGHT:
                    if(sj+1>=N) break;
                        if(map[si][sj+1]==YES){
                            map[si][sj+1] = NO;
                            q.push(make_pair(si, sj+1));
                        }
                    break;
                case TOP:
                    if(si-1<0) break;
                        if(map[si-1][sj]==YES){
                            map[si-1][sj] = NO;
                            q.push(make_pair(si-1, sj));
                        }
                    break;
                case BOTTOM:
                    if(si+1>=N) break;
                        if(map[si+1][sj]==YES){
                            map[si+1][sj] = NO;
                            q.push(make_pair(si+1, sj));
                        }
                    break;

            }
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
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==NO) continue;
                room = 0;
                BFS(i,j);
                result.push_back(room);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++)
        cout << result[i] << "\n";
}