/*
    https://www.acmicpc.net/problem/13549

    문제
        *원래는 그냥 queue로 범위를 산정해 풀어보려 했지만 실패했다.

    풀이
        1. 숨바꼭질이랑 거의 똑같다.
        2. 다만, 여기선 순간이동이 0초를 소모하게 되었다.
        3. 가장 빠른 시간을 구하려면 경과시간이 짧은 것을 먼저 탐색하도록 해야한다.
        4. 따라서, priority_queue를 사용하도록 하자

    알아야 할 점
        * 27번줄 처럼 선언해야 오름차순이 된다. 즉, top()값이 가장 작은 값이다.
        * 또한, pair를 사용했을 땐 first값 기준으로 정렬된다.
        * first값 이 같다면 second 값 기준으로..
        * 또한 greater대신 자신이 만든 class를 사용해도 좋다!
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
using namespace std;
int S, D;
bool Visited[100001];
priority_queue< pair<int , int>, vector< pair<int, int> >, greater<pair<int,int> > > q;
vector<int> re;
int result=100001;
int main()
{
    cin >> S >> D;

    q.push(make_pair(0,S));
    Visited[S]=true;

    while(!q.empty())
    {
        int time = q.top().first;
        int x = q.top().second;
        q.pop();
        //cout << x << " ";
        if(x==D){ result=time; break;}
        

        //2*x
        if(2*x < 100001 && !Visited[2*x]){//2*x <= 2*D 
            Visited[2*x] = true;
            q.push(make_pair(time,2*x));
        }
        //+1
        if(x+1<100001 && !Visited[x+1]){
            Visited[x+1] = true;
            q.push(make_pair(time+1,x+1 ));
        }
        //-1
        if(x-1>=0 && !Visited[x-1]){
            Visited[x-1] = true;
            q.push(make_pair(time+1,x-1));
        }

    }
    cout << result << "\n";
}
// #include <iostream>
// #include <queue>
// #include <utility>
// #include <vector>
// using namespace std;
// int S, D;
// bool Visited[100001];
// queue< pair<int , int> > q;
// vector<int> re;
// int result=100001;
// int main()
// {
//     cin >> S >> D;

//     q.push(make_pair(S,0));
//     Visited[S]=true;
//     while(!q.empty())
//     {
//         int x = q.front().first;
//         int time = q.front().second;
//         q.pop();
//         //cout << x << " ";
//         if(x==D){ result=min(result,time);}
//         //-1
//         if(time > abs(D-S)) continue;

//         if(x-1>=0 && !Visited[x-1]){
//             Visited[x-1] = true;
//             q.push(make_pair(x-1,time+1));
//         }
//         //+1
//         if(x+1<100001 && !Visited[x+1]){
//             Visited[x+1] = true;
//             q.push(make_pair(x+1, time+1));
//         }

//         //2*x
//         if(2*x < 100001 && !Visited[2*x]){//2*x <= 2*D 
//             Visited[2*x] = true;
//             q.push(make_pair(2*x,time));
//         }
//     }
//     cout << result << "\n";
// }