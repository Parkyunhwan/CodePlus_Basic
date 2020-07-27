/*
    https://www.acmicpc.net/problem/15666

    값이 하나라도 있으면 연속 중복이 가능한 조합을 구하는 문제
    1. 하나만 있어도 중복이 가능하므로 갯수를 셀 필요가 없음
    2. 중복된 숫자는 하나로 취급한다.
    3. 선택된 숫자로만 이루어진 조합을 구한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N,M;
vector<int> v;
vector<int> result;
void DFS(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0; i < M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = idx; i < v.size(); i++)
    {
        result.push_back(v[i]);
        DFS(cnt+1, i);
        result.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i < N; i++)
    {
        int num;
        cin >> num;
        if( v.end() == find(v.begin(), v.end(), num) )
            v.push_back(num);
    }
    sort(v.begin(), v.end());
    DFS(0,0);
}