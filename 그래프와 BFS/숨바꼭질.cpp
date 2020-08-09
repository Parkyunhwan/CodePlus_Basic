/*
    https://www.acmicpc.net/problem/1697
    
    전형적인 BFS 문제
    어떻게 하면 경우의 수를 줄일 수 있는지 핵심이였다.
    
    * 조건
    1. 방문 한 곳은 다시 안간다.
    2. 현재값에 2배가 결과값의 2배보다 크면 안간다.
    
    ** 틀린 조건은 없는 조건보다 못하다.
        -> 41번째 줄 처럼 모든 상황을 고려하지 못하는 조건은 없느니만 못하다.
*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N,K;
int chance=0;
enum direction {BACK,FRONT,DOUBLE};
bool Visited[100001];
int main()
{
    cin >> N >> K;
    queue< pair<int, int> > q;
    Visited[N]=true;
    q.push(make_pair(N,0));
    while(!q.empty())
    {
        int cur = q.front().first;
        int val = q.front().second;
        q.pop();
        if(cur == K){ chance = val; break;}
        val++;
        if(cur-1 == K || cur+1 == K || 2*cur == K){ chance = val; break;}
        for(int i=0; i<3; i++){
            switch(i)
            {
                case BACK:
                    if(cur-1<0 ) break;
                    //if( (cur*2) < K) break;
                    if(Visited[cur-1]==true) break;
                    Visited[cur-1] = true;
                    q.push(make_pair(cur-1,val));
                    break;
                case FRONT:
                    if(cur+1>K) break;
                    if(Visited[cur+1]==true) break;
                    Visited[cur+1] = true;
                    q.push(make_pair(cur+1,val));
                    break;
                case DOUBLE:
                    if(2*cur > 100000 || cur*2 >= 2*K) break;
                    if(Visited[2*cur]==true) break;
                    Visited[2*cur] = true;
                    q.push(make_pair(2*cur,val));
                    break;
            }   
        } 
    }
    cout << chance << "\n";
}