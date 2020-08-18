/*
    https://www.acmicpc.net/problem/1463

    생각
        다이나믹 프로그래밍 푼 지 오래 되서 기억도 안났다.
        기억하기 프로그래밍 이라고 생각하고 접근했다.

    풀이
        1. BFS와 비슷한 접근법. 먼저 주어진 조건을 만족하는 값들을 모두 큐에 넣는다.
        2. 큐에 넣기 전에 이전에 방문 기록이 있는지 확인한다.
        3. 이전의 방문기록이 무조건 빠를 수 밖에 없으므로 재방문 하지 않는다.
        4. 다음 단계로 진입한다.
        5. 이전에 있는 값들을 이용해 최솟값을 빠르게 산출해낸다.
        

*/
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int N;
int cache[1000001];
int main()
{
    cin >> N;
    q.push(N);
    cache[N]=0;
    int result;
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        if(num==1){result = cache[num]; break;}
        //cout << "num" << num << "\n"; 
        if(num%3==0){
            if(cache[num/3]==0){ 
            cache[num/3]=cache[num]+1;
            q.push(num/3);
                //cout << num/3 << cache[num]+1 << "\n";
            }
        }

        if(num%2==0){
            if(cache[num/2]==0){ 
            cache[num/2]=cache[num]+1;
            q.push(num/2);
                //cout << num/2 << cache[num]+1 << "\n";
            }
        }

        if(num-1>0){
            if(cache[num-1]==0){ 
            cache[num-1]=cache[num]+1;
            q.push(num-1);
                //cout << num-1 << cache[num]+1 <<"\n";
            }
        }
    }
    cout << result << "\n";
}