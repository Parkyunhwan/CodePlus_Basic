/*
    https://www.acmicpc.net/problem/14226

    생각
    경우를 나눠서 계속해서 파악해야하는 문제 - > BFS

    *풀이
    1. 종이에 3가지 경우의 수를 써가면서 풀었다.
    2. pair와 2차원 배열을 적절히 사용해서 풀었다.

    TIP
        queue< pair< pair<int,int>, int> > Q;
        -> 이렇게 하면 2가지가 아닌 3가지를 등록해서 쓸 수 있다!!
*/
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
queue< pair<int, int> > q;
int S;
int Visited[1001][1001];
int main()
{
    cin >> S;
    int result;
    q.push(make_pair(1,0));
    Visited[1][0]=1;
    while(!q.empty())
    {
        int display = q.front().first;
        int clip = q.front().second;
        q.pop();
        // cout << display << " " << clip << " ";
        // cout << Visited[display][clip] << "\n";
        if(S == display) {result = Visited[display][clip]-1; break;}
        int val = Visited[display][clip]+1;

        if(display>0){
            if( Visited[display][display]==0){
                Visited[display][display]=val;
                q.push(make_pair(display, display));
            }
        }

        if(clip>0 && display+clip <= 1000){
            if( Visited[display+clip][clip]==0){
                Visited[display+clip][clip]=val;
                q.push(make_pair(display+clip, clip));
            }
        }

        if(display>0 && clip > 0){
            if( Visited[display-1][clip]==0){
                Visited[display-1][clip]=val;
                q.push(make_pair(display-1,clip));
            }
        }
    }
    cout << result << "\n";
}