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
        cout << V[i] << " "; // 저장된 순서대로 꺼내서 출력한다.
    }
    cout << endl;
}

void DFS(int cnt)
{
    if(cnt==3)
    {
        Print();
        return;
    }
    for(int i=0; i < MAX; i++) // 0 부터 즉 처음부터 다시 진행하는 것을 볼 수 있다.
    {
        if (Select[i]==true) continue;
        Select[i] = true;
        V.push_back(Arr[i]); //vector에 보관함으로 순서를 정해줄수 있다 (Point)
        DFS(cnt+1); // idx는 시작점부터 다시 체크해야 하기 때문에 없어지고 cnt만을 사용한다.
        V.pop_back();
        Select[i]=false;
    }
}
int main(void)
{
    for(int i=0; i<MAX;i++)
        Arr[i]=i+1;

    DFS(0);
}