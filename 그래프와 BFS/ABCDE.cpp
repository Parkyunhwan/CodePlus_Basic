/*
    https://www.acmicpc.net/problem/13023

    다시 풀어보길..

    1. 입력된 관계를 각각의 값에 저장한다.
    2. vertex에서 다음 vertex를 찾는다. (이 때 이미 갔던 vertex는 제외하고 새로운 vertex만 가도록 한다.)
    3. 다음 vertex가 없다면 이전 vertex로 돌아가서 다시 경로를 탐색한다.
    4. 시작 vertex부터 연속적으로 이어진 vertex가 4개 이상이면 1을 출력한다.
 
*/
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2000;
int N,M;
bool Visit[MAX], Answer;
vector<int> V[MAX];

void Input()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int a,b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
}

void DFS(int idx, int Cnt)
{
    if(Cnt == 5)
    {
        Answer = true;
        return;
    }
    Visit[idx] = true;

    for(vector<int>::size_type i=0; i< V[idx].size(); i++){
        int Next = V[idx][i];
        if(Visit[Next] == true) continue;
        DFS(Next, Cnt + 1);
        if(Answer == true) return;
    }
    Visit[idx] = false;
}

void Solution()
{
    for(int i=0; i < N; i++)
    {
        memset(Visit, false, sizeof(Visit));
        DFS(i, 1);
        if(Answer == true) break;
    }

    if(Answer == true) cout << 1 << endl;
    else cout << 0 << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    Solve();
    return 0;
}