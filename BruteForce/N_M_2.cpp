#include <iostream>

using namespace std;
const int MAX = 8;

int N, M;
int arr[MAX]; // 범위 제한 참고

void itergo(int idx)
{
    if(idx == M) // 출력 단계
    {
        for(int i=0; i < M; i++)
        {
            cout << arr[i] << " "; // M만큼 출력
        }
        cout << "\n"; // endl 보다 속도

        return;
    }

    for( int i = (idx==0) ? 1 : arr[idx - 1]+1; i <= N; i++)
    {
        arr[idx] = i; // 4 라면 1, 2, 3, 4 을 순차적으로 대입
        itergo(idx + 1); 
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin, cout 의 속도 향상을 위해 사용!

    cin >> N >> M; 

    itergo(0);

    return 0;
}