#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

enum color{NONE,RED,BLUE};
int N, M;
bool result[2];
vector<int> v[20001];
queue<int> q;
int checked[20001]={0,};

bool BFS(int idx)
{
    int col = RED;
    q.push(idx);
    checked[idx] = RED;
    while(!q.empty()){
        int next = q.front();
        q.pop();

        // if(checked[next]==RED)
        //     col = BLUE;
        // else if(checked[next]==BLUE)
        //     col = RED;

        for(int i=0; i<v[next].size(); i++){
            int element = v[next][i];
///////
////////
//////
            if(checked[element]==NONE){
                switch(checked[next]){
                    case RED:
                        checked[element]=BLUE;
                        break;
                    case BLUE:
                        checked[element]=RED;
                        break;
                //checked[element]=col;
                }
                q.push(element);
            }  
            else if(checked[element]==checked[next]) {
                while(!q.empty()) q.pop();
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int num;
    cin >> num;
    int i=0;
    for(int i=0; i<num; i++){
        cin >> N >> M;
        for(int j=0; j<M; j++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

    for(int j=1; j<=N;j++){
        if(checked[j]==NONE)
            result[i]=BFS(j);
        if(result[i]==false)
            break;
    }
        for(int k=1; k<20001; k++)
            v[k].clear();
        memset(checked,0,sizeof(checked));
    }

    for(int i=0; i<num; i++){
        if(result[i])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
}
/*
    https://www.acmicpc.net/problem/1707

    일단 오류가 너무 많았다.
    [오류]
    1. 시간초과
        switch 문을 29번째 줄 for문 안에 넣었는데 시간 초과가 일어났다.
        switch문과 if문의 속도 차이는 아닌 듯하다.
        단지 for문안에서 검사 하나 차이인데 왜 시간 초과가 났는지 모르겠다.

        --> 다시 바꿔보니 아니다.. 다른 문제 였던 것 같다.

    2. 나머지 연결요소들도 검사를 했는가?
        한번만 BFS를 실행하면 연결되지 않은 다른 노드들은 검사되지 않는다.
        이 부분은 방문하지 않은 노드 부터 다시 BFS를 시작한다.
    
    3. 2번을 수행하면서 이미 방문 했다면 반드시 멈춰야 했다.
        그렇지 않으면 앞의 결과를 덮을 수 있다.
    
*/