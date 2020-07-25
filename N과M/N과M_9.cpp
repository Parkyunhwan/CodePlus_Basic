/*
    기존에 풀던 방식에서 막힌 문제

    다른 방식을 참고했다.
    1. map을 이용해 각 값의 갯수를 저장해둔다. - 중복되는 값이 하나의 key로 저장되고 그 갯수가 저장됨
    2. 정말 신기하게도 중복되는 값을 하나로 합치므로 한번만 재귀함수를 실행할 수 있다.
    3. 또한 그 갯수를 기록해둠으로써 9 9 같은 출력은 가능케 했다.

*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 8;
int N,M;
int arr[MAX];
int visited[MAX];
vector<int> v;
map<int, int> numberCnt;
void DFS(int cnt)
{
    if(cnt == M)
    {
        for(int i=0; i < M; i++){
                cout << v[visited[i]] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(numberCnt[v[i]])
        {
            numberCnt[v[i]]--;
            visited[cnt] = i;
            DFS(cnt + 1);
            numberCnt[v[i]]++;
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i < N; i++){
        int num;
        cin >> num;

        if(!numberCnt.count(num)) //key값에 해당하는 원소가 없으면 추가
        {
            numberCnt[num] = 1; //key의 value에 1 대입
            v.push_back(num);
        }
        else
        {
            numberCnt[num]++; //key값에 해당하는 원소가 있다면 값을 증가시킴
        }
    }
    sort(v.begin(), v.end());
    DFS(0);
}