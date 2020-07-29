/*
    https://www.acmicpc.net/problem/13023
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