#include <iostream>

using namespace std;
const int MAX = 5;
const int SLTNUM = 3;
int Arr[MAX]={1,2,3,4,5};
bool Select[MAX];
void Print()
{
    for(int i = 0; i < MAX; i++)
    {
        if( Select[i] == true)
        {
            cout << Arr[i] << " ";
        }
    }
    cout << "\n";
}

void DFS(int idx, int cnt)
{
    if(cnt==SLTNUM)
    {
        Print();
        return;
    }

    for (int i = idx; i < MAX; i++)
    {
        if(Select[i] == true) continue; //선택 했었다면 뒤에 부분 무시하고 다음 idx 진행
        Select[i] = true; //선택 안했다면 선택으로 변경

        DFS(i,cnt+1); //선택 갯수를 늘리고 재귀
        Select[i]=false; 
    }
}

int main()
{
    DFS(0,0);
}