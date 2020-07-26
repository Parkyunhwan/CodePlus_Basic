/*
    https://www.acmicpc.net/problem/15665

    * 값이 하나라도 있으면 연속 중복이 가능한 순열을 구하는 문제
    
    1. 연속 중복이 가능하기 때문에 갯수 조건이 사라졌다.
    2. 중복되는 입력 값을 하나로 통합 한다.
    3. 유일한 값들로 연속 중복 순열을 구성한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N,M;
int result[8];
vector<int> v;
map<int, int> vNum;
void DFS(int cnt)
{
    bool Select[8];
    if(cnt==M){
        for(int i=0; i < M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<v.size(); i++)
    {
        result[cnt] = v[i];
        DFS(cnt+1);
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i < N; i++)
    {
        int num;
        cin >> num;
        // if(!vNum.count(num)){
        //     vNum[num] = 1;
        //     v.push_back(num);
        // }
        if( v.end() == find(v.begin(), v.end(), num)) v.push_back(num);
        else vNum[num]++;

        sort(v.begin(), v.end());
    }
    DFS(0);
}