/*
    순열과 조합의 차이는 순서의 차이

    순열은 조합과 달리 시작점을 다시 한번 봐줘야 한다

    {1,2,3} -> {2,1,3} 2 이전의 1의 숫자도 봐줘야한다.

    * Vector를 사용하여 순서를 유지한다.
*/
#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

int Arr[MAX];
bool Select[MAX];
vector<int> V;

void Print()
{
    for(int i=0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << "\n";
}

void DFS(int Cnt)
{
    if(Cnt == 3)
    {
        Print();
        return;
    }

    for(int i=0; i < MAX; i++){
        if(Select[i] == true)
            continue;
        V.push_back(Arr[i]);
        Select[i] = true;
        DFS(Cnt+1);
        V.pop_back();
        Select[i]=false;
    }
}

int main()
{
    for(int i=0; i < MAX; i++){
        Arr[i] = i+1;
    }
    DFS(0); // 조합과 달리 따로 idx(시작점)을 넣어주지 않는다
}