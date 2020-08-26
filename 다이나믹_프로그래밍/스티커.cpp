/*
    https://www.acmicpc.net/problem/9465

    생각
        단계별로 그림을 그렸을 때 될 수 있는 경우들을 찾아낼 수 있었다.
        하지만 문제는 불확실한 못한 예외 상황들을 생각하면서 점화식과 코딩을 만들지 못했다.
        dp문제는 값을 저장해가는 경우가 많으므로 너무 이전 값에 대해서는 연연하지 않는다는 것을 알아두자.

    풀이
        두 가지만 생각하면 되는 문제이다.
        1. 2행일 때 전 (0행)대각선 값과 전전 대각선의 값의 비교 후 큰 것 선택
        2. 1행일 때 전 (2행)대각선 값과 전전 대각선의 값의 비교 후 큰 것 선택

        해당 점화식을 통해 조건내의 최댓값을 구할 수 있다.
    
    TIP
        *삼항연산자랑 max() 는 속도차이는 거의 없는 것 같다.
        *sync_with_stdio(false)를 적용시킨 cin은 scanf()보다 빠를 때가 있다. (적어도 이 코드 내에선) 아마도 싱글 cpu 사용 시 라고 추측해본다. 
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long d[100001][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;
    //scanf("%d",&num);
    while(num--){
        int N;
        cin >> N;
        //scanf("%d",&N);
        for(int i=0; i<2; i++){
            for(int j=1; j<=N; j++){
                //scanf("%d",&d[j][i]);
                cin >> d[j][i];
            }
        }
        for(int i=2; i<=N; i++){
            d[i][0] += max(d[i-1][1],d[i-2][1]);
            d[i][1] += max(d[i-1][0],d[i-2][0]);
            //d[i][0] += (d[i-1][1] > d[i-2][1] ? d[i-1][1] : d[i-2][1]);
            //d[i][1] += (d[i-1][0] > d[i-2][0] ? d[i-1][0] : d[i-2][0]);
        }
        cout << max(d[N][0],d[N][1]) << "\n";

    }


}