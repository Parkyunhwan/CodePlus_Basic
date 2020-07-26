/*
    두 개의 조건식에서 충돌이 일어났던 문제.

    1. Select조건문을 통해 중복 선택이 불가능하게 했다.
    2. 현배열값과 다음배열값을 비교해 같으면 하나만 선택하도록 했다.

    이 두 조건이 결합되어 1 7 9 9 에서 9 9는 선택될 수 없었다.
    여기서 flag를 통해 1번 Select조건문 바로 다음 배열에는 2번조건을 검사하지 않도록 했다.

    그래서 9 9 가 선택될 수 있도록 하였다.

    ** 기존의 풀던 방식과 다른 방식을 참고함 -꾸준함 블로그-
    1. map 자료구조를 통해 값과 값의 갯수를 연관지어 저장했다. (중복된 값을 하나로 저장함)
    2. 기존에 쓰던 Select배열 대신 값의 개수를 통해 중복 선택을 방지 한다.

    3. N과M 9번과 다른 점은 시작점을 지정하느냐 안하느냐의 차이인 순열과 조합의 차이였다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 8;
int N,M;
bool Select[MAX];
int result[MAX];
vector<int> v;
map<int,int> arrCount;
void DFS(int cnt, int idx)
{

    if(cnt == M)
    {
        for(int i=0; i<M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=idx; i<N; i++){
        // if(Select[i]==true) continue;
        // Select[i]=true;
        if(arrCount[ v[i] ])
        {
            arrCount[v[i]]--;
            result[cnt]=v[i];
            DFS(cnt+1, i);
            arrCount[v[i]]++;
        }
        // Select[i]=false;
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(!arrCount.count(num)){
            arrCount[num]=1;
            v.push_back(num);
        }
        else{
            arrCount[num]++;
        }
    }
    sort(v.begin(),v.end());
    DFS(0,0);
}