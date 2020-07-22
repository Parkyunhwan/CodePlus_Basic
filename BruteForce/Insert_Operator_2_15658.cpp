/*
    https://www.acmicpc.net/problem/15658
    * 재귀 함수는 완전 탐색이라는 무식하게 모두 세는 방식을 사용하여 알고리즘을 짤 때 좋다.
    
    * DFS처럼 동작하는 재귀함수
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int N;
vector<int> result;
void solve(int index, int sum, int plus, int minus, int multi, int div, vector<int> num)
{
    if(index == N){ // 기저 조건 (base case)
        result.push_back(sum);
        return;
    }
    if(plus != 0) solve(index + 1, sum + num[index], plus - 1, minus, multi, div, num);
    if(minus != 0) solve(index + 1, sum - num[index], plus, minus - 1, multi, div, num);
    if(multi != 0) solve(index + 1, sum * num[index], plus, minus, multi - 1, div, num);
    if(div != 0) solve(index + 1, sum / num[index], plus, minus, multi, div - 1, num);

}
int main()
{
    cin >> N;
    vector<int> number(N);
    vector<int> oper(4);

    for(int i=0; i < N; i++)
        cin >> number[i];
    for(int i=0; i < 4; i++)
        cin >> oper[i];
    
    solve(1, number[0], oper[0],oper[1],oper[2],oper[3], number);

    auto res = minmax_element(result.begin(), result.end());
    printf("%d\n%d\n", *res.second, *res.first);
}
