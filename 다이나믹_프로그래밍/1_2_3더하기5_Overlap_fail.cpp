/*
    이 로직이 안되는 이유!

        모듈러 연산이 있을 때 뺄셈은 오류의 발생지인 것 같다.
        모듈러 연산 후 뺄셈은 음수의 확률을 높인다. 

        조심하고 반례를 생각하자.

        숫자가 커진다면 점점 오류의 확률이 증가한다.

*/
#include <iostream>

using namespace std;
long long d[100001];
long long overlap[100001][4];
int main()
{
    int num;
    cin >> num;
    overlap[1][1]=1;
    overlap[2][2]=1;
    overlap[3][1]=1;
    overlap[3][2]=1;
    overlap[3][3]=1;
    d[1]=1; d[2]=1; d[3]=3;
    for(int i=0; i<num; i++)
    {
        int N;
        cin >> N;
        for(int i=4; i<=N; i++){
            long long sum = overlap[i-1][1] + overlap[i-2][2] + overlap[i-3][3];
            d[i] =( (d[i-1] + d[i-2] + d[i-3]) - sum )%1000000009;
            //cout << overlap[i-1][1] << overlap[i-2][2] << overlap[i-3][3] << "\n";
            if(d[i-1] - overlap[i-1][1]>0)
                overlap[i][1] = (d[i-1] - overlap[i-1][1])%1000000009;
            if(d[i-2] - overlap[i-2][2]>0)
                overlap[i][2] = (d[i-2] - overlap[i-2][2])%1000000009;
            if(d[i-3] - overlap[i-3][3]>0)
                overlap[i][3] = (d[i-3] - overlap[i-3][3])%1000000009;
        }
        cout << d[N] << "\n";
    }
}