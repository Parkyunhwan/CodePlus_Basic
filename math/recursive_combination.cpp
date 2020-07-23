/*
    재귀로 조합을 구현 할 땐
    시작점을 결정한 이후 , 그전의 요소는 다시 보지 않는다.
    {1, 2, 3}...{1, 4, 5} - {2,...} -> 1은 더이상 보지도 않는다.

    재귀 조합의 핵심은 돌아 보지 않는다는 것!
     
    참고한 블로그 - https://yabmoons.tistory.com/99
*/
#include <iostream>
#define MAX 5
using namespace std;

int Arr[MAX];
bool Select[MAX];

void Print()
{
    for(int i=0; i < MAX; i++)
    {
        if(Select[i]==true)
        {
            cout << Arr[i] << " ";
        }
    }
    cout << "\n";
}
void DFS(int Idx, int Cnt)
{
    if(Cnt == 3) // 기저 조건
    {
        Print();
        return;
    }

    for(int i = Idx; i < MAX; i++)
    {
        if (Select[i] == true)
            continue;

        Select[i] = true;
        
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}

int main()
{  
    for(int i=0; i < MAX; i++)
        Arr[i] = i+1;
    
    DFS(0, 0);
}